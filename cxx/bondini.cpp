#include <iostream>

int main(int argc, char* argv[])
{
	using namespace std;
	std::cout << "\aOpreation \"HyperHype\" is now activated!\n";
	std::cout << "Enter your agent code:________\b\b\b\b\b\b\b\b";
	long code;
	std::cin >> code;
	std::cout << "\aYou entered " << code << "...\n";
	std::cout << "\aCode verified! Proceed with Plan Z3!\n";

	return 0;
}

