#include "mem_roster.h"
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/types.h>
#include <unistd.h>
#include <assert.h>
#include <stdlib.h>

int main(int argc, char* argv[]){
	std::string* text = new std::string();
	MemRoster::getInstance()->checkin(text, sizeof(text), __FILE__, __LINE__);

	 int fd = open("abc.txt", O_RDWR, O_CREAT|O_APPEND);
	if (fd < 0)
		assert(false);
	MemRoster::getInstance()->print(fd);
	close(fd);

	return 0;
}

