#include <iostream>
#include "data_type.hpp"

int main(int argc, char* argv[]){

	Integer val1(10);
	Integer val2(20);

	std::cout << "please input val1:";
	std::cin >> val1;
	std::cout << "please input val2:";
	std::cin >> val2;

	Integer sum = val1 + val2;

	std::cout << "val:" << val1 << "+val2:" << val2 << "=" << sum << std::endl;

	return 0;
}
