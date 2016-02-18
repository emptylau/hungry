#include <stdio.h>
#include <string>
#include <iostream>
#include <string.h>

int main(int argc, char* argv[])
{
	std::string name {"jcheng lau"};
	char cname[] = {"jcheng lau"};

	std::cout << name << "\t" << sizeof(name) << "\t" << name.size() << std::endl;
	std::cout << cname << "\t" << sizeof(cname) << "\t" << strlen(cname) << std::endl;

	return 0;
}
