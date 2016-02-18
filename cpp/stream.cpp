 /********************************************************************
 # File Name:    stream.cpp
 # Version:      1.0
 # Mail:         jchenglau@163.com 
 # Created Time: 2015-11-24
 *********************************************************************/

#include <iostream>
#include <sstream>

int main(int argc, char* argv[])
{

	std::string word;
	std::string input;

	std::getline(std::cin, input);
	std::istringstream input_str(input);
	while (input_str >> word) {
		std::cout << word << std::endl;
	}

	return 0;
}

