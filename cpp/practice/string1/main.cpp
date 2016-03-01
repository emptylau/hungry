#include <iostream>
#include <algorithm>
#include <functional>
#include "string.h"

int main(int argc, char* argv[])
{
	std::cout << __LINE__ << std::endl;
	String str("What's up");

	std::cout << __LINE__ << std::endl;
	String *pStr = new String("...What's up!");

	std::cout << "str: " << str << std::endl;
	std::cout << "pStr: " << *pStr << std::endl;

	delete pStr;

	std::cout << __LINE__ << std::endl;
	str = (String)"Hello World!";
	std::cout << "str = (Hello World!)" << str << std::endl;

	std::cout << __LINE__ << std::endl;
	int len = str.size();
//	std::reverse(&str[0], &str[len]); // use STL algorithm .. e.g base by iterator 
	str.reverse(); // using user defined class-method

	std::cout << "reverse --> str = " << str << std::endl;

	std::cout << __LINE__ << std::endl;
	String test = String("why not"); 
	std::cout << __LINE__ << std::endl;

	//test = std::move(str); // 强制移动构造 
	//test = str; 
	const String test1(test);
	test = test1;

	return 0;
} 



