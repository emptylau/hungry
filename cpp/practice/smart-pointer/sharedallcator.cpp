#include <iostream>
#include <memory>
#include <string>

class String{

public:
	String(const char* str):data(str){
		std::cout << __FUNCTION__ << std::endl;
	}

	~String(){
		std::cout << __FUNCTION__ << std::endl;
	};

private:
	std::string data;

};

// 分配器的使用
int main(int argc, char* argv[]){

	std::shared_ptr<int> data(new int, 
			std::default_delete<int>(), 
			std::allocator<int>());

	std::shared_ptr<String> str(new String("hello"), 
			std::default_delete<String>(),
			std::allocator<String>()); // 分配器用于 shared_ptr 的内部数据

	return 0;
}

