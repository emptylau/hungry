#include <stdio.h>
#include  <iostream>

int main(int argc, char* argv[])
{
	double earings[4] {1.2e4, 1.6e4, 1.1e4, 1.7e4};

	for (auto d: earings){
		std::cout << d << " ";
	}
	std::cout << std::endl;

	unsigned int counts[10] = {};
	for (auto c: counts){
		std::cout << c << " ";
	}
	std::cout << std::endl;

	float balance[100] {};
	for (auto b: balance){
		std::cout << b << " ";
	}
	std::cout << std::endl;

	return 0;
}
