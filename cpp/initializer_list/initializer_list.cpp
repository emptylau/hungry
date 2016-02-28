#include <stdio.h>
#include <iterator>
#include  <iostream>
#include <initializer_list>
#include <algorithm>
#include <functional>
#include <sstream>


template <typename T>
void print(std::initializer_list<T>);


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

	std::cout << "-----" << std::endl;

	print<float>({1.1, 2.0, 3.0});
	std::cout << std::endl;

	print({1, 2, 3});
	std::cout << std::endl;

	return 0;
}

template <typename T>
void print(std::initializer_list<T> args){

	std::for_each(args.begin(), args.end(), [](const T& elem){
			std::cout << " " << elem;
			});
	//std::copy(args.begin(), args.end(), std::ostream_iterator<T>(std::cout, " "));
	//std::cout << std::endl;

	//std::transform(args.begin(), args.end(), std::ostream_iterator<T>(std::cout, " "), std::bind1st(std::plus<T>(), 10));
	
	/*
	std::ostringstream os;
	std::transform(args.begin(), args.end(),
			args.begin(), std::ostream_iterator<T>(os, " "), std::plus<T>());
	std::cout << os.str() << std::endl;
	*/
	
}
