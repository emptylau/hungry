#include <iostream>
#include <functional>

using namespace std::placeholders;

// mem_fn 测试 普通成员函数转换；操作符绑定
struct Printer{
	int data;
	int operator()(){
		return data;
	}

	void print(const char* flag){
		std::cout << "called by " << flag
			<< " " << data << std::endl;
	}
};

int main(int argc, char* argv[]){

	// c++11 initializer_list constructor
	Printer obj = {10};
	std::cout << obj() << std::endl;

	obj.print("obj.print");

	// mem_fn 转换
	auto func = std::mem_fn(&Printer::print);

	obj.data = 100;
	func(obj, "mem_fun");

	// bind 绑定
	auto func2 = std::bind(&Printer::print, &obj, _1);
	func2("bind");

	// bind操作符函数绑定
	auto func3 = std::bind(&Printer::operator(), &obj);
	std::cout << "bind operator() " << func3() << std::endl;

	// mem_fn 操作符转换为普通函数
	auto func4 = std::mem_fn(&Printer::operator());
	std::cout << "mem_fun operator() " << func4(obj) << std::endl;

	return 0;
}
