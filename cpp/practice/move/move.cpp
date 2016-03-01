#include <iostream>
#include <functional>
#include <string>

// std::move 测试
int main(int argc, char* argv[]){

	std::string* myname = new std::string("jcheng");

	std::string subname = *myname;
	std::cout << "myname:"  << *myname << std::endl;
	std::cout << "subname:"  << subname << std::endl;

	*myname = std::move(subname);
	delete myname;

	//std::cout << "myname:"  << *myname << std::endl;
	std::cout << "subname:"  << subname << std::endl;

	return 0;
}
