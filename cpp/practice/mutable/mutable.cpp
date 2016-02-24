#include <iostream>

struct Data{
	int id;
	mutable int data;
};


int main(int argc, char* argv[]){

	const Data data1 = {1, 100};

	std::cout << "id = " << data1.id << std::endl;
	std::cout << "data = " << data1.data << std::endl;

	data1.data++; // 注意，这里只有mutable 才可以修改
	std::cout << "modified data increment 1" << std::endl;
	std::cout << "\tid = " << data1.id << std::endl;
	std::cout << "\tdata = " << data1.data << std::endl;

	return 0;
}
