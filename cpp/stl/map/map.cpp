#include <iostream>
#include <map>
#include <stdlib.h>
#include <stdio.h>


int main(int argc, char* argv[])
{
	typedef std::map<int, int>::iterator iterator;

	srand(time(0));
	std::map<int, int> first;
	for (int index = 0; index < 10; ++index){
		auto ret = first.insert(std::make_pair(rand()%20, index));
		if (!ret.second) {
			std::cout << "插入失败:" << ret.first->second << ' ' \
				<<  ret.first->first << std::endl;
		}
	}

	first.insert(std::pair<int,int>(21, 11));
	auto unknow = first.erase(21);

	int abc = 0;
	std::cout << abc << std::endl;

	puts("-------");

	for (auto itr: first){
		std::cout << itr.first << " " << itr.second << std::endl;
	}

	puts("--------");
	for (auto itr = first.begin(); itr != first.end(); ++itr){
		std::cout << itr->first << " " << itr->second << std::endl;
	}

	return 0;
}
