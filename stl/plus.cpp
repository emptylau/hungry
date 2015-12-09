#include <iostream>
#include <functional>

// std::plus 是一个类，而并不是一个模板函数
//  该类同时也是一个函数对象
int main(int argc, char* argv[])
{
    std::cout << std::plus<int>()(10, 10) << std::endl;
    return 0;
}
