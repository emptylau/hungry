#include <set>
#include <iostream>
#include "entry.h"

struct SCompareEntry{

	explicit SCompareEntry(int id):m_key(id){
		sign = 0;
	}
	
	SCompareEntry(const SCompareEntry& other){
		if (this != &other){
			m_key = other.m_key;
			sign = other.sign;
		}
	}

	bool operator<(SCompareEntry& other) const {
		return m_key < other.m_key;
	}

	bool operator<(const SCompareEntry& other) const{
		return m_key < other.m_key;
	}

	int sign;
	Entry<int> m_key;
};

int main(int argc, char* argv[])
{
	SCompareEntry obj1(20);
	SCompareEntry obj2(30);
	SCompareEntry obj3(10);
	obj3.sign = 1;
	SCompareEntry obj4(10);
	obj4.sign = 2;

	SCompareEntry obj5(10);
	obj5.sign = 3;

	std::multiset<SCompareEntry> obj_multiset;
	obj_multiset.insert(obj1);
	obj_multiset.insert(obj2);
	obj_multiset.insert(obj3);
	obj_multiset.insert(obj4);
	obj_multiset.insert(obj5);


	for (auto itr: obj_multiset){
		std::cout << itr.m_key.get_id() << std::endl;
	}

	puts("");
	auto lower = obj_multiset.lower_bound(obj3);
	auto upper = obj_multiset.upper_bound(obj3);
	while (lower != upper){
		std::cout << lower->m_key.get_id() << " " << lower->sign << std::endl;
		++lower;
	}
	
	return 0;
}
