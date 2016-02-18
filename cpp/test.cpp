#include <iostream>

int func(int n);


int main(int argc, char* argv[])
{

	int n = 100;

	int sum = func(n);

	std::cout << sum << std::endl;

	return 0;
}

int func(int n)
{
	int sum = 0;
	int i = 1;
	for(; i <= n; ++i) {
		sum += i;	
	}

	return sum;
}
