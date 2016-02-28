#include <iostream>
#include <set>

// 测试 set 元素值是否能够直接改变
 


int main(int argc, char* argv[]){


	std::set<double> scores;

	scores.insert(1.01);
	scores.insert(4.02);
	scores.insert(0.3);
	scores.insert(2.1);

	std::cout << "original set:\n";
	for (auto elem: scores){
		std::cout << " " << elem;
	}
	std::cout << std::endl;


	std::cout << "modified set:\n";
	for (auto& elem: scores){
		++elem;
		std::cout << " " << elem;
	}
	std::cout << std::endl;

	return 0;
}
