#include <iostream>
#include <string>

// 联合的访问限制测试
// 1. 其实联合和结构体差不多，只是联合采用共享内存的方式来组织数据。
// 2. 但也因为这个共享的特性,导致了联合不支持静态的/const/引用类型的数据，因为这让共享怎么办？
// 3. 还有一点点区别，它无法保证能够调用成员数据里对象的构造和析构等构造方法，因此不支持对析构和构造有要求的对象。。无构造的结构还是可以的。

// 联合类定义
 union Data{
 public:
	 Data(int v):nValue(v){
	 }

	 Data(float v):fValue(v){

	 }

	 operator int() const{
		 return nValue;
	 }
	 
	 operator float() const {
		 return fValue;
	 }

 private:
	 int nValue;
	 float fValue;
};


int main(int argc, char* argv[]){

	Data data(10);
	std::cout << (int)data << std::endl;

	Data real(20.2f);
	std::cout << (float)real << std::endl;

	//real.nValue =10; // 编译错误，访问受限
	std::cout << (float)real << std::endl;

	return 0;
}

