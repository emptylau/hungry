 /********************************************************************
 # File Name:    readlink.cpp
 # Version:      1.0
 # Mail:         jchenglau@163.com 
 # Created Time: 2015-12-02
 *********************************************************************/

#include <iostream>
using namespace std;


int main(int argc, char* argv[]){

	char exec_name[1024] = {0};
	readlink("/proc/self/exe", exec_name, 1024);

	printf("%s\n", exec_name);

	return 0;
}
