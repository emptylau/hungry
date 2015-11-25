#include <unordered_set>
#include <set>
#include <iostream>
#include <string>
#include <sstream>
#include <stdlib.h>

// unordered_set 的使用，以及set 同 unorderd_set 查找比较
// 结论：unordered_set 的查找速度确实要不set快4成的样子
int main(int argc, char* argv[])
{
	if (argc < 3) {
		std::cout << "a.out count find_key" << std::endl;
		return 0;
	}

	int count = atoi(argv[1]);
	std::string key(argv[2]);

	std::set<std::string> name_set;
	name_set.insert("jcheng");
	name_set.insert("emptylau");
	name_set.insert("ljc");
	name_set.insert("1234");
	name_set.insert("_abc");

	puts("std::set -->");

	for (auto itr: name_set){
		std::cout << itr << std::endl;
	}

	clock_t tick = clock();
	for (int index = 0; index < count; ++index){
		std::stringstream strstream;	
		strstream << index;
		name_set.insert(strstream.str());
	}

	{
		auto itr = name_set.find(key);
		if (itr != name_set.end()){
			std::cout << *itr << std::endl;
		} else {
			std::cout << "not found" << std::endl;
		}
	}
	std::cout << "ticks: " << clock() - tick << std::endl;

	puts("std::unordered_set -->");
	std::unordered_set<std::string> name_unordered_set({"jcheng", "emptylau", "ljc"});
	name_unordered_set.insert("_abc");
	name_unordered_set.insert("1234");

	for (auto itr: name_unordered_set){
		std::cout << itr << std::endl;
	}
	
	clock_t tick1 = clock(); 
	for (int index = 0; index < count; ++index){
		std::stringstream strstream;
		strstream << index;
		name_unordered_set.insert(strstream.str());
	}

	{
		std::unordered_set<std::string>::iterator itr;
		if ( (itr = name_unordered_set.find(key)) != name_unordered_set.end()){
			std::cout << *itr << std::endl;
		} else {
			std::cout << "not found" << std::endl;
		}
	}

	std::cout << "ticks: " << clock() - tick1 << std::endl;

	return 0;
}
