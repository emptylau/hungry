#include <iostream>
#include "number.h"
#include "bignumber.h"

int main(int argc, char* argv[]){

	Number obj(10);
	BigNumber big(20);
	std::cout << "big->";
	big.desc();

	Number* pobj = &obj;
	BigNumber* pbig = &big;
	std::cout << "pbig->";
	pbig->desc();

	int* data = reinterpret_cast<int*>(pobj);
	std::cout << "Number* -> int*: " << *data << std::endl;

	int& qobj = reinterpret_cast<int&>(obj);
	std::cout << "Number& -> int&: "<< qobj << std::endl;


	return 0;
}


