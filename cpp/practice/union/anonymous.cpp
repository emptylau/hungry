#include <iostream>
#include <typeinfo>

// 匿名枚举测试
// 全局的一定要是static 吗？ 
//	是的，当然还可以是放在匿名命名空间

// 1. 加 static
/*static union {
	int nValue;
	float fValue;
};*/

// 2 匿名命名空间
namespace {
	union {
		int nValue;
		float fValue;
	};
};

int main(int argc, char* argv[]){

	nValue = 10;
	decltype(fValue) f;
	const auto& info = typeid(f);

	//std::cout << typeid(decltype(nValue)).name() << std::endl;
	std::cout << "name: " << info.name() << std::endl;
	std::cout << "hash_code: " << info.hash_code() << std::endl;

	return 0;
}


