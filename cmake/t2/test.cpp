#include <iostream>
#include "log.h"

//namespace T1{
#define FORMAT_STR(a, b, c) #a" "#b" "#c" = %d\n",a b c 
#define TEST_M(a, b, c) #a" "#b" "#c" = %d\n", 10
#define TEST_ADD(a,b) #a" + "#b" = %d\n", (a) + (b)
//};

using namespace T2;
int main(int argc, char* argv[])
{
    CLog::debug("Hello World\n");
    CLog::debug("1 + 1 = %d\n", 2);
    CLog::debug("1 + 2.0 = %f\n", 1 * 2.0);
    CLog::debug(FORMAT_STR(1,+,10));
    CLog::debug(TEST_M(1,+,2));
    CLog::error(TEST_ADD(10,10));

    return 0;
}
