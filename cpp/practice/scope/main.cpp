#include <iostream>

// 注意，不用#include file1.cpp. 全局变量保存在全家符号表中的
extern int data1; // 该变量定义file1.cpp中
extern void print2();

extern int sum(int dt);

static int total = sum(20);

int main(int argc, char* argv[]){
	
	//extern int data1; // 不可以在这里引入外部变量，否则会导致data1的重复定义
	int data1 = 100;

	std::cout << "local data1 = " << data1 << std::endl;
	// 使用作用域操作符::来使用全局变量
	std::cout << "extern data1 = " << ::data1 << std::endl;

	print2();

	//	static int total = 10; // 静态变量的初始化之一：常量初始化
	//	static int total = 10 + UINT_MAX; // 静态变量的初始化之二：常量表达式初始化
	//static int total = sum(10); // 静态变量的初始化之三：动态初始化
	std::cout << "total = " << total << std::endl;

	return 0;
}
