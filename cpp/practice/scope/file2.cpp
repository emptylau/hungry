
#include <iostream>

static int data1 = 20; 

void print2(){

	std::cout << __FILE__ << " static data1 = " << data1 << std::endl; 

	extern int data1;
	std::cout << __FILE__ << " ::data1 = " << ::data1 << std::endl;
}

int sum(int dt){
	return ++dt;
}
