
#include <stddef.h>
#include <assert.h>

/*
char* strcpy(char* strDest, const char* strSrc){
	if (!strDest || !strSrc)
		return NULL;

	char* dest = strDest;
	// 注意，字符串结束符 0 不能忘掉了
	while ((*dest++ = *strSrc++) && '\0'  != *dest);


	return strDest;
}
*/

char* strcpy(char* strDest, const char* strSrc){

	assert(NULL != strDest && NULL != strSrc);

	char* dest = strDest;

	// \0会被拷贝
	while ((*dest++ = *strSrc++) != '\0');

	return strDest;
}

size_t strlen(const char* str){

	size_t len = 0;
	const char* p = str;
	while (*p++)
		++len;

	return len;
}

int strcmp(const char* strSrc, const char* strDest){

	const char* src = strSrc;
	const char* dest = strDest;

	while (*src == *dest && !*src){
		++src;
		++dest;
	}

	if (*src > *dest)
		return 1;
	else if (*src < *dest)
		return -1;

	return 0;
}

