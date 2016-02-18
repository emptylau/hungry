 /********************************************************************
 # File Name:    cstringlen.cpp
 # Version:      1.0
 # Mail:         jchenglau@163.com 
 # Created Time: 2015-11-20
 *********************************************************************/

#include <iostream>
using namespace std;

int main(int argc, char* argv[])
{

	const char* cstr = "";
	
	int len = sizeof(cstr);

	std::cout << len << std::endl;

	return 0;
}
	

