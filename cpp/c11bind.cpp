 /********************************************************************
 # File Name:    c11bind.cpp
 # Version:      1.0
 # Mail:         jchenglau@163.com 
 # Created Time: 2015-11-20
 *********************************************************************/

#include <iostream>
#include <functional>

using namespace std::placeholders;


void print(int nValue)
{
	std::cout << nValue << std::endl;
}

void func(std::function<void(int)> function, int nValue)
{
	function(nValue);
}

int main(int argc, char* argv[])
{

	func(std::bind(print, _1), 10);

	return 0;
}
