#include <iostream>
#include <set>

int main(int argc, char* argv[])
{
	std::set<int> vec_1 = {1, 2, 3};

	int data[] = {4, 5, 6, 7};
	std::set<int> vec_2(data, data+4);

	puts("set 1:");
	for (auto itr: vec_1){
		std::cout << itr << std::endl;
	}
		
	puts("set 2:");
	for (auto itr: vec_2){
		std::cout << itr << std::endl;
	}

	puts("swap after:");
	vec_1.swap(vec_2);

	for (auto itr: vec_1){
		std::cout << itr << std::endl;
	}

	for (auto itr: vec_2){
		std::cout << itr << std::endl;
	}

	return 0;
}

