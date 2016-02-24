#ifndef _PRINT_H_
#define _PRINT_H_

#include <iostream>

static void print(int sum){
	std::cout << __FUNCTION__ << " " << sum << std::endl;
}

#endif // _PRINT_H_
