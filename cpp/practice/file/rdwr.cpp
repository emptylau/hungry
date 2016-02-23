#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[]){

	FILE* file = fopen("abc.txt", "a+");
	if (NULL == file)
		return 0;

	char buff[] = __FILE__"\n"; 
	fwrite(buff, sizeof(char), strlen(buff), file);
	fclose(file);

	return 0;
}
