#include "string.h"
#include <iostream>
#include <stdlib.h>

void test1();
void test2();

int main(int argc, char* argv[]){

	char* text = (char*) malloc(20);
	std::cout << __FUNCTION__ << " no assignment value. text = " << std::endl;

	test1();
	test2();

	return 0;
}

void test1(){

	char* text = (char*)malloc(10);

	strcpy(text, "hello");
	std::cout << __FUNCTION__  << " text = " << text << std::endl;

	free(text);
	text = NULL;
}

void test2(){
	char* text = (char*)malloc(10);
	strcpy(text, "hello");
	free(text);

	strcpy(text, "world");

	std::cout << __FUNCTION__  << " free after: text = " <<  text << std::endl;
	text = NULL;
}

