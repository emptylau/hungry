#include "mem_roster.h"
#include <unistd.h>
#include <string.h>

void MemRoster::checkin(void* mem, int size, const char* file, int line){
	MemInfo* pInfo = new MemInfo();	
	pInfo->ptr = (PTR)mem;
	int filename_size = strlen(file) + 1;
	pInfo->file = new char[filename_size];
	strncpy(pInfo->file, file, filename_size - 1);
	pInfo->file[filename_size-1] = '\0';
	pInfo->size = size;
	pInfo->line = line;
	m_mtx.lock();
	if(m_rosters.end() != m_rosters.find((PTR)mem)){
		m_mtx.unlock();
		printf("%s %d [%p] memery overlap",file, line, mem);
		return;
	}
	m_rosters.insert(std::make_pair(pInfo->ptr, pInfo));
	m_mtx.unlock();

}

void MemRoster::checkout(void* mem){

	m_mtx.lock();
	auto iter = m_rosters.find((PTR)mem);
	if (iter != m_rosters.end()){
		if (!iter->second && iter->second->file) {
			delete iter->second->file;
			delete iter->second;
		}
		m_rosters.erase(iter);
	}
	m_mtx.unlock();

}

void MemRoster::print(int fd){
	m_mtx.lock();
	for(auto& elem: m_rosters){
		if (elem.second && elem.second->file){
			char buff[48] = {0};
			sprintf(buff, "%s %d [0x%x] is not release!\n", elem.second->file, elem.second->line, elem.second->ptr);
			write(fd, buff, strlen(buff));
			delete elem.second->file; 
			delete elem.second;
		} 
	}
	m_rosters.clear(); 
	m_mtx.unlock(); 
} 
