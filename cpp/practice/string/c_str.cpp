#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>
#include <cstring>
#include <iterator>

/*
extern "C"{
	int toupper(int);
}
*/

// 1. 测试 std::string::c_str() 返回的C-style 是不是字面字符串
// 2. 测试 c_str() 和 data() 有什么区别
int main(int argc, char* argv[]){

	std::string data(10, 'c');

	// 获得 c_str 返回的字符串
	const char* cstr = data.c_str(); 
	std::cout << "[before] str:" << cstr << std::endl;
	// win32下data()其实调用的是c_str()
	std::cout << "[before] data:" << data.data() << std::endl; 

	// 将const char* 强制转换为 char* 以便后续更改字符串内容
	char* pstr = const_cast<char*>(cstr);
	int size = strlen(pstr);

	// 改变 c_str 返回的字符串
	//std::transform(pstr, pstr+size, pstr, [](char c){ return toupper(c); });
	std::transform(pstr, pstr+size, pstr, ::toupper);

	// 输出测试结果
	std::cout << "[after] data:" << data.c_str() << std::endl;
	std::cout << "[after] str:" << cstr << std::endl;

	data.assign(3, 'd');
	std::cout << "c_str() length:" << strlen(data.c_str()) << std::endl;
	std::cout << "data() length:" << strlen(data.data()) << std::endl;

	return 0;
}
