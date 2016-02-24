#include <iostream>

/*
// static使该函数失去了外部链接性
static void print(int sum){
	std::cout << __FUNCTION__ << " " << sum << std::endl;
}

// const 可以是全局变量失去外部链接性，但不可以使函数失去链接性
const void print(int sum){

}
*/

void print(int sum){
	std::cout << __FUNCTION__ << " " << sum << std::endl;
}
