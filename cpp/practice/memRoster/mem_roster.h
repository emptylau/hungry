#ifndef _MEM_ROSTER_H_
#define _MEM_ROSTER_H_

#include <map>
#include <mutex>
#include <sys/types.h>
#include "single.h"

#if __WORDSIZE == 64
	typedef __uint64_t PTR;
#else
	typedef __uint32_t PTR;
#endif

struct MemInfo{
	int ptr;
	int size;
	char* file;
	int line;
};

class MemRoster: public Single<MemRoster>{

public:
	MemRoster(){}
	~MemRoster(){}

	void checkin(void* mem, int size, const char* file, int line);
	void checkout(void* mem);

	void print(int fd);

	int size(){
		return m_rosters.size();
	};

private:
	std::map<int, MemInfo*> m_rosters;
	std::mutex m_mtx;
};

#endif //!_MEM_ROSTER_H_
