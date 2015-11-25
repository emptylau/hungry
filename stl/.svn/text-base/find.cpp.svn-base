#include <algorithm>
#include <vector>
#include <iostream>



bool func(int value, int target)
{
	if (target == value ){
		return true;
	}

	return false;
}

template <typename T>
struct Comparer{

	Comparer(T target):target(target){
		std::cout << __FUNCTION__ << std::endl;
	};

	bool operator()(T value){

		if(value == target)
			return true;

		return false;
	}

	T target;
	
};

int main(int argc, char* argv[])
{

	if (3 != argc) {
		std::cout << "usage: find count target" << std::endl;
		return 0;
	}


	int count = atoi(argv[1]);
	int target = atoi(argv[2]);

	std::vector<int> vData;

	for(int index = 0; index < count; ++index){

		vData.push_back(index + 1);
	}

#if 0
	auto iter = find(vData.begin(), vData.end(), target);
	if (iter != vData.end()){
		std::cout << "find success: " <<  *iter << std::endl;
	}
	else{
		std::cout << "the value: " << *iter << "not found" << std::endl;
	}

#else


	if( vData.end() != find_if(vData.begin(), vData.end(), Comparer<int>(target)) ){
		std::cout << "find success" << std::endl;
	}
	else {
		std::cout << "not found!" << std::endl;
	}

		
#endif

	return 0;
}
