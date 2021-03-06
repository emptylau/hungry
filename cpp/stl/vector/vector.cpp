#include <vector>
#include <iostream>
#include <stdlib.h>

int main(int argc, char* argv[])
{
	std::vector<int> first;

	srand(time(0));
	for (int index = 0; index < 5; ++index){
		first.push_back(rand() % 20);
	}

	for (auto itr: first){
		std::cout << itr << std::endl;
	}

	std::vector<int>::iterator itr;
	for ( itr = first.begin(); itr != first.end(); ++itr ){
		std::cout << *itr << std::endl;
	}

	return 0;
}
