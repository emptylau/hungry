#include <iostream>
#include <iterator>
#include <algorithm>
#include <cstdio>
#include <functional>


// std::begin / std::end 练习
int main(int argc, char* argv[]){

	int data[] = {1, 2, 3, 4, 5};

	// 这里的end需要自己知道数组大小
	std::copy(data, data+5, std::ostream_iterator<int>(std::cout, " "));
	std::cout << std::endl;

	std::sort(data, data+5, std::greater<int>());
	//std::for_each(data, data+5, [](int elem){ std::cout << elem << " ";} );
	//注意：std::end 不用知道 data 到底有多少个元素
	std::copy(std::begin(data), std::end(data), std::ostream_iterator<int>(std::cout, " "));
	std::cout << std::endl;
	
	return 0;
}
