#include <iostream>
#include <random>

int main(int argc, char* argv[]){


	std::random_device rd;
	for (int n = 0; n < 100; ){
		std::cout << rd() << " ";

		if ( 0 == ++n % 5)
			std::cout << std::endl;
	}
	
	return 0;
}
