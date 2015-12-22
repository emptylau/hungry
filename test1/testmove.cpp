 /********************************************************************
 # File Name:    testmove.cpp
 # Version:      1.0
 # Mail:         jchenglau@163.com 
 # Created Time: 2015-11-23
 *********************************************************************/

#include <iostream>
#include <string>

/*
template <typename T>
void print(T& data) {
	std::cout << data << std::endl;	
}

template <typename T>
void print(const T& data){
	std::cout << data << std::endl;
}
*/

template <typename T>
void print(T&& data){
	std::cout << data << std::endl;
}




int main(int argc, char* argv[])
{
	int num = 10;
	print<int>(std::move(num));

	print<int>(123);
	print<const char*>("123");

	return 0;
}
