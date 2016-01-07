 /********************************************************************
 # File Name:    main.cpp
 # Version:      1.0
 # Mail:         jchenglau@163.com 
 # Created Time: 2015-11-23
 *********************************************************************/

#include <iostream>
#include <stdio.h>
#include "pig.h"
using namespace std;

int main(int argc, char* argv[])
{

	std::string hello = "hello";
	std::string lala = "lala";

	Pig pigLala(lala);

	Pig temp(std::string("123"));
	temp = Pig(hello);

	return 0;

}

