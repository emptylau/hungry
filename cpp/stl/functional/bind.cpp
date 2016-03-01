#include <iostream>
#include <functional>

// 测试bind:
// 1. bind 绑定时，使用的是对象的地址吗？
//  都可以，对象做参数时会拷贝一个对象保存
// 2. bind 绑定后，更改了对象的属性，执行结果同原绑定对象执行方法调用后得到的结果相同吗？
//  如果是对象做参数，结果不一下
//  如果对象地址做参数，结果相同

using namespace std::placeholders;

struct Dog{
	std::string name;
	float height;

	void info(const char* holder){
		std::cout << "name: " << name << std::endl;
		std::cout << "holder:" << holder << std::endl;
		std::cout << "height:" << height << std::endl;
	}

	const std::string& getName(){
		return name;
	}

};

int main(int argc, char* argv[]){

	Dog dog = {"dog1", 19.02f};

	std::cout << "\n---采用的绑定对象---" << std::endl;
	dog.info("emp");
	// 对象绑定时，直接传入对象。。。这里开销比较大
	auto func1 = std::bind(&Dog::info, dog, _1);
	func1("jch1");

	std::cout << "体重+1" << std::endl; 
	// 改变 dog 的体重，比较执行结果
	dog.height += 1; 
	dog.info("emp1");
	func1("jch1");

	std::cout << "\n---采用的绑定对象地址---" << std::endl;
	// 对象绑定时，直接使用对象地址
	dog.info("emp2");
	auto func2 = std::bind(&Dog::info, &dog, _1);
	func2("jch2");

	std::cout << "体重+1" << std::endl;
	dog.height += 1;
	dog.info("emp2");
	func2("jch2");

	auto func3 = std::bind<const std::string&>(&Dog::getName, &dog);
	std::cout << "有返回值的绑定测试: " << func3() << std::endl; 

	return 0;
}
