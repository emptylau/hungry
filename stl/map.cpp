#include <iostream>
#include <map>


int main(int argc, char* argv[])
{
	typedef std::map<int, int>::iterator iterator;

	std::map<int, int> first;
	for (int index = 0; index < 5; ++index){
		auto ret = first.insert(rand()%20);
		if (ret.second) {
			std::cout << "插入失败:" << ret.first << std::endl;
		}
	}

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
