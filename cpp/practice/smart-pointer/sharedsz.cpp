#include <iostream>
#include <string>
#include <memory>
#include <iterator>

template <typename T>
struct Deleter{
	void operator()(T t[]){
		delete []t;
	}
};

// 数组的使用
int main(int argc, char* argv[]){

	int count = 20;
	std::shared_ptr<int> datalist(new int[count], Deleter<int>(), std::allocator<int>());
	int* pdata = (int*)datalist.get();
	std::fill(pdata, pdata+count, 10);

	std::copy(pdata,pdata+count, std::ostream_iterator<int>(std::cout, " "));
	std::cout << std::endl;

	return 0;
}

