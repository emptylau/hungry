#include <iostream>

/**
 * c++动态数组的实现
 **/

int main(int argc, char* argv[]){

	int num = 10;
//	int *data = new int[num]; // 动态数组
	int data[num] = {0}; // g++ 4.9 可以直接编译通过
	int tmp[0];

	std::cout << "int tmp[0]: size=" << sizeof(tmp) << std::endl;
	char name[1];
	name[0] = 'a';
	std::cout <<"char name[1]; name[0]=" << name[0] << std::endl;;

	std::cout << "output dynamic array values:" << std::endl;
	int elem;
	for (int idx = 0; idx < num; ++idx){
		elem = data[idx];
		std::cout << elem << " ";
	}
	std::cout << std::endl;
	return 0;
}
