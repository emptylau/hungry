#ifndef _LOG_H_
#define _LOG_H_

namespace T2{
#define FORMAT_STR(a, b, c) #a" "#b" "#c" = %d\n",a b c 
#define TEST_M(a, b, c) #a" "#b" "#c" = %d\n", 10
#define TEST_ADD(a,b) #a" + "#b" = %d\n", (a) + (b)
};

class CLog{
public:
    CLog();
    ~CLog();

public:
   static void debug(const char* log_info, ...);
   static void error(const char* log_info, ...);
};

#endif
