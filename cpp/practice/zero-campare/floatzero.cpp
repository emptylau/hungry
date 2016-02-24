#include <iostream>

/**
 * float 的零值比较
 */

// 精度
const float EPSINON = 0.00001;

int main(int argc, char* argv[]){


	float value = 0.00011;
	if (value >= -EPSINON && value <= EPSINON){
		std::cout << "vlaue == 0.0" << std::endl;
	}
	else {
		std::cout << "value != 0.0" << std::endl;
	}
	
	return 0;
}
