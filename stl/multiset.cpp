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

	std::multiset<SCompareEntry> obj_multiset;
	obj_multiset.insert(obj1);
	obj_multiset.insert(obj2);
	obj_multiset.insert(obj3);
	std::multiset<SCompareEntry>::iterator ret = obj_multiset.insert(obj3);


	for (auto itr: obj_multiset){
		std::cout << itr.m_key.get_id() << std::endl;
	}
	
	return 0;
}