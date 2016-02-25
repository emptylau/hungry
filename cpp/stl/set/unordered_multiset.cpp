#include <iostream>
#include <unordered_set>

int main(int argc, char* argv[])
{
	std::unordered_multiset<int> unoredered_mset({1, 2, 23, 3});
	for (auto itr: unoredered_mset){
		std::cout << itr << std::endl;
	}

	return 0;
}


