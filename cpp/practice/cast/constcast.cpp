#include <iostream>
#include "number.h"
#include "bignumber.h"

int main(int argc, char* argv[]){

	Number obj(10);
	const BigNumber big(20);

	// 引用形式
	BigNumber& qbig = const_cast<BigNumber&>(big);
	qbig.change(21);
	std::cout << "BigNumber& ->" << qbig << " orig = " << big << std::endl; // BigNumber 继承了Number 类型转换函数

	// 指针形式
	BigNumber* pbig = const_cast<BigNumber*>(&big);
	pbig->change(22);
	std::cout << "BigNumber* ->" << *pbig << " orig = " << big << std::endl;

	std::cout << "big = " << big << std::endl;

	// 基础类型
	const int MAX = 10;
	int* ret = const_cast<int*>(&MAX);
	*ret = 11;
	std::cout << "int& ret = " << *ret << " MAX = " << MAX << std::endl;

	return 0;
}


