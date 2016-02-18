#include <iostream>

int main(int argc, char* argv[])
{
	int n = 0;;

inc:
	++n;
	goto end;

dec:
	--n;

end:
	std::cout << "n = " << n << std::endl;;

	return 0;
}
