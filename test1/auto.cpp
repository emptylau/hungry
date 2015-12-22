 /********************************************************************
 # File Name:    auto.cpp
 # Version:      1.0
 # Mail:         jchenglau@163.com 
 # Created Time: 2015-11-20
 *********************************************************************/

#include <iostream>
#include <typeinfo>
using namespace std;


void print(auto data)
{
	std::cout << typeid(data).name() << " "<< data << std::endl;
}

int main(int argc, char* argv[])
{

	print("123");
	print(123);
	print(123.01);
		

	return 0;
}

