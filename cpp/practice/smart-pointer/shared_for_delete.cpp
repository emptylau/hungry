#include <iostream>
#include <string>
#include <memory>


template <typename T>
struct Deleter{
	void operator()(T* obj){
		std::cout << "Deleter" << std::endl;
		delete obj;
	}
};


// shared_ptr 的使用
int main(int argc, char* argv[]){

	// 普通版本
	std::shared_ptr<std::string> pstr(new std::string("123"));
	std::cout << *pstr << std::endl;

	// 定制删除器
	std::shared_ptr<std::string> pDe(new std::string("delete control"), Deleter<std::string>());
	std::cout << *pDe << std::endl;

	// 使用默认的删除器
	std::shared_ptr<std::string> pdef(new std::string("245"), std::default_delete<std::string>());
	std::cout << "default delete" << std::endl;

	return 0;
}
