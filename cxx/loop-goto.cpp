#include <iostream>

int main(int argc, char* argv[])
{
	int n = 0;

//	goto nor;

	{
inc:
	++n;

	}

nor:
	if (n < 10)
		goto inc;
	else
		goto done;
done:
	std::cout << "n = " << n << std::endl;

	return 0;
}

