 /********************************************************************
 # File Name:    remote.cpp
 # Version:      1.0
 # Mail:         shiyanhk@gmail.com 
 # Created Time: 2015-11-17
 *********************************************************************/

#include <iostream>
#include <time.h>

using namespace std;

int main(int argc, char* argv[])
{

	for (int index = 0; true; index ++) {

		std::cout << "sleep: " << index + 1 << std::endl;

		sleep(1);
	}

	return 0;
}

