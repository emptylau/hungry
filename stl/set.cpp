#include <set>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>


// 函数对象
struct SCompareInt
{
	bool operator()(int lhs, int rhs){
		return lhs > rhs;
	}
};

// 比较函数
bool fnCompare(int lhs, int rhs){
	return lhs < rhs;
}

// 输出模板
template <typename T> 
void fnPrint(T& obj){
	for (auto itr: obj){
		std::cout << itr << std::endl;
	}
}

int main(int argc, char* argv[])
{
	srand(time(0));
	std::set<int> first;

	// 给set<int>定义一个别名，方便后面编码
	typedef std::set<int> IntSet;

	int num_seq[] = {1, 4, 3, 5};

	puts("使用数字初始化:");
	std::set<int> second(num_seq, num_seq + 4);
	fnPrint<std::set<int>>(second);

	puts("拷贝构造");
	std::set<int> third(second);
	fnPrint<IntSet>(third);

	puts("支持迭代器参数的构造");
	std::set<int> fourth(third.begin(), third.end());
	fnPrint<IntSet>(fourth);

	puts("在定义时指定比较函数对象");
	std::set<int, SCompareInt> fifith;
	for (int index = 0; index < 5; ++index) {
		fifith.insert(random() % 30);
	}
	fnPrint<std::set<int, SCompareInt>>(fifith);

	puts("在定义时指定比较函数");
	bool (*pfnCompare)(int,int) = fnCompare;
	std::set<int, bool(*)(int,int)> sixth(pfnCompare);

	int nTemp = 0;
	for (int index = 0; index < 5; ++index){
		nTemp = random() % 20;
		std::cout << nTemp << " ";
		if (!sixth.insert(nTemp).second) {
			std::cout << "重复key值，插入失败" << nTemp << std::endl;
		}
	}
	puts("");
	fnPrint<std::set<int, bool(*)(int,int)>>(sixth);
	//fnPrint<std::set<int>>(sixth); // 这样是不被认可的，因为模板实例化后并不是同一个类

	return 0;
}
