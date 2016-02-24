#ifndef _STRING_H_
#define _STRING_H_
#include <stddef.h>

extern char* strcpy(char* strDest, const char* strSrc);
extern size_t strlen(const char* str);
extern int strcmp(const char* strSrc, const char* strDest);

#endif

