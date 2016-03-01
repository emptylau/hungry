#include <iostream>
#include <random>
#include <vector>

int main(int argc, char* argv[]){

	const int nrolls = 10000;
	const int nstars = 95;

	//std::default_random_engine generator;
	std::discard_block_engin generator;
	std::uniform_int_distribution<int> distr(0, 9);

	std::vector<int> data(10);

	for (auto& elem: data){
		elem = distr(generator);
		std::cout << elem << std::endl;
	}

	std::cout << "uniform_int_distribution(0,9):" << std::endl;
	for (int idx = 0; idx < data.size(); ++idx){
		std::cout << idx << ": " << std::string(data[idx], '*') << std::endl;;
	}

	return 0;
}
