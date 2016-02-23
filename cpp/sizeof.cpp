 /********************************************************************
 # File Name:    cstringlen.cpp
 # Version:      1.0
 # Mail:         jchenglau@163.com 
 # Created Time: 2015-11-20
 *********************************************************************/

#include <iostream>
using namespace std;

void test(const char* text){
	//"注意：在传递过程中,sizeof已经失效";
	std::cout << "const char* text = \"12345\"; sizeof(text)= " << sizeof(text) << std::endl;

}

int main(int argc, char* argv[])
{

	const char* cstr = "";
	int len = sizeof(cstr);
	std::cout << "const char* cstr=""; sizeof(cstr)=" << len << std::endl;

	short ages[10] = {0};
	std::cout << "short ages[10]; sizeof(ages)=" << sizeof(ages) << std::endl;

	short *ptr = NULL;
	std::cout << "short *ptr; sizeof(ptr)=" << sizeof(ptr) << std::endl;


	char text[] = "12345";
	test(text);

	return 0;
}
	

