#include <iostream>
#include <vector>
#include <algorithm>

// 练习： std::tansform std::copy std::for_each
// 这几个模板函数在使用时，都必须要注意到:
// 1. 拷贝的性能，以及遍历的边界问题。
// 2. 在遍历的过程中，都是以 *elem_iterator的方式来传递参数的。
template<typename T>
void print(T elem){
    std::cout << elem << " "; 
}

int main(int argc, char* argv[])
{
	std::vector<int> data = {1, 2, 3, 4};

    std::cout << "data: " << std::endl;
    std::for_each(data.begin(), data.end(), print<int>);
    std::cout << std::endl;

	std::vector<int> result;
	result.resize(data.size());

	std::transform(data.begin(), data.end(), result.begin(), [](int elem){
		return elem * 2;
	});

    std::cout << "transform: elem*2" << std::endl;
    std::for_each(result.begin(), result.end(), print<int>);
    std::cout << std::endl;

	std::vector<int> dup;
	dup.resize(data.size());

	std::copy(data.begin(), data.end(), dup.begin());

    std::cout << "copy: " << std::endl;
    std::for_each(dup.begin(), dup.end(), print<int>);
    std::cout << std::endl;

    int array[] = {1, 2, 3, 4};
    result.resize(dup.size());
	std::transform(dup.begin(), dup.end(), 
			array, //data.begin(),
			result.begin(), 
			[](int elem1, int elem2){
				return elem1 * elem2;
			});

    std::cout << "transform: elem1 * elem2" << std::endl;
    std::for_each(result.begin(), result.end(), print<int>);
    std::cout << std::endl;

	return 0;
}
