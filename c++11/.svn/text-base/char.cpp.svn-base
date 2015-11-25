#include <stdio.h>
#include <typeinfo>
#include <iostream>
#include <string>

int main(int argc, char* argv[])
{
	auto autostr = "auto";
	std::string strings = "std::string";
	const char* cstring = "const char*";

	std::cout << autostr  << "\t" <<  typeid(autostr).name() << std::endl;
	std::cout << strings << "\t" << typeid(strings).name() << std::endl;
	std::cout << cstring << "\t" << typeid(cstring).name() << std::endl;

	auto intlong = 1L;
	auto longlong = 1LL;

	printf("intlong %ld %s %d\n", intlong, typeid(intlong).name(), sizeof(intlong));
	printf("longlong %lld %s %d\n", longlong, typeid(longlong).name(), sizeof(longlong));

	auto floatdigit = 1.0f;
	auto doubledigit = 1.0;
	auto longdoubledigit = 1.0L;

	printf("floatdigit %f %s %d\n", floatdigit, typeid(floatdigit).name(), sizeof(floatdigit));
	printf("doubledigit %lf %s %d\n", doubledigit, typeid(doubledigit).name(), sizeof(doubledigit));
	printf("longdoubledigit %llf %s %d\n", longdoubledigit, typeid(longdoubledigit).name(), sizeof(longdoubledigit));

	wchar_t wchar = 'A';
	std::cout.put(wchar);
	std::cout << std::endl;

	std::cout << '$' <<  " ";
	std::cout.put('$');
	std::cout << std::endl;

	std::cout << sizeof(std::string) << std::endl;
	std::cout << "wchar_t: " << sizeof(wchar) << std::endl;
	return 0;
}
