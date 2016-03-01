#include <iostream>

// 大小端测试
union Magic{
	unsigned short value;
	struct {
		char high;
		char low;
	}data;
};

int main(int argc, char* argv[]){

	Magic md;

	md.value = 0x6162;

	std::cout << "low: " << md.data.low << std::endl;
	std::cout << "high: " << md.data.high << std::endl;

	if (0x41 == md.data.low)
		std::cout << "order: big-endian" << std::endl;
	else 
		std::cout << "order: little-endian" << std::endl;

	return 0;
}
