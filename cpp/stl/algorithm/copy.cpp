#include <iostream>
#include <iterator>
#include <algorithm>
#include <vector>


int main(int argc, char* argv[]){

	std::vector<int> datas(10);

	copy(std::istream_iterator<int, char>(std::cin), 
			std::istream_iterator<int, char>(), 
			datas.begin());

	std::cout << "inputs:" << std::endl;
	/*
	for (auto elem: datas){
		std::cout << " " << elem;
	}
	*/
	copy(datas.begin(), datas.end(), 
			std::ostream_iterator<int, char>(std::cout, "\n"));
//	std::cout << std::endl;

	return 0;
}
