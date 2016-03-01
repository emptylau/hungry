#include <iostream>
#include <iterator>
#include <vector>

// std::ostream_iterator 练习
int main(int argc, char* argv[]){

	std::vector<int> data;

	for (int idx = 0; idx < 10; ++idx){
		data.push_back(rand()%10);
	}

	std::ostream_iterator<int> out(std::cout, "\n"); // 第二个参数，每输出一次都会输出
	std:copy(data.begin(), data.end(), out);

	return 0;
}
