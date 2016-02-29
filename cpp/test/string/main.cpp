#include <iostream>
#include <algorithm>
#include "string.h"

int main(int argc, char* argv[])
{
	String str("What's up");
	String *pStr = new String("...What's up!");

	std::cout << "str: " << str << std::endl;
	std::cout << "pStr: " << *pStr << std::endl;

	delete pStr;

	str = "Hello World!";
	std::cout << "str = (Hello World!)" << str << std::endl;

	int len = str.size();
//	std::reverse(&str[0], &str[len]); // use STL algorithm .. e.g base by iterator 
	str.reverse(); // using user defined class-method

	std::cout << "reverse --> str = " << str << std::endl;

	return 0;
} 



