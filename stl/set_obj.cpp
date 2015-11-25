#include <set>
#include <iostream>
#include "entry.h"

struct SCompareEntry{

	explicit SCompareEntry(int id):m_key(id){
	}
	
	SCompareEntry(const SCompareEntry& other){
		if (this != &other){
			m_key = other.m_key;
		}
	}

	bool operator<(SCompareEntry& other) const {
		return m_key < other.m_key;
	}

	bool operator<(const SCompareEntry& other) const{
		return m_key < other.m_key;
	}

	Entry<int> m_key;
};

int main(int argc, char* argv[])
{
	SCompareEntry obj1(20);
	SCompareEntry obj2(30);
	SCompareEntry obj3(10);

	std::set<SCompareEntry> obj_set;
	obj_set.insert(obj1);
	obj_set.insert(obj2);
	obj_set.insert(obj3);
	std::pair<std::set<SCompareEntry>::iterator, bool> ret = obj_set.insert(obj3);
	if (!ret.second){
		std::cout << "insert failure:" << ret.first->m_key.get_id() << std::endl;
	}


	for (auto itr: obj_set){
		std::cout << itr.m_key.get_id() << std::endl;
	}
	
	return 0;
}
