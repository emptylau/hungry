#include <iostream>
#include <functional>
#include <string>


// std::hash 测试 char* 和 string的区别
// 注意：std::hash<char*> h; 并不是计算 char* 类型的字符串，实质上它只是个地址
int main(int argc,char* argv[]){

	char cstr1[] = "TEST";
	char cstr2[] = "TEST";
	std::string str1(cstr1);
	std::string str2(cstr2);

	// hash并没有C风格字符串的计算方式，这里计算是char*的地址
	std::hash<char*> ptr_hash;
	std::hash<std::string> str_hash;

	std::cout << "c-style(real pointer address): " 
		<< ptr_hash(cstr1) << " " 
		<< ptr_hash(cstr2) << std::endl;

	std::cout << "string: " 
		<< str_hash(cstr1) << " " 
		<< str_hash(cstr2) << std::endl;

	return 0;
}



