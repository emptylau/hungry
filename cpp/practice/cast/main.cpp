#include <iostream>
#include "number.h"

int main(int argc, char* argv[]){

	int data1 = 10;
	Number obj(10);

	data1 += obj;

	std::cout << "int + Number: " << data1 << std::endl;

	data1 += obj();
	std::cout << "int + Number::operator()() " << data1 << std::endl;

	return 0;
}
