#include <cstdio>
#include <functional>
//#include "EventManager.h"
#include "event_set.hpp"


void print(){
    printf("%s test ok!\n", __FUNCTION__);
}

void print2(int data){
    printf("%s %d", __FUNCTION__, data);
}

int main(int argc, char* argv[])
{
    CEvent<void()> event_handler;
    //event_handler += std::bind(*print);
    //event_handler += *print;
    
    event_handler();

    std::function<void()> fun1 = print;
    std::function<void()> fun11 = print;
    std::function<void(int)> fun2 = print2;

#if 0
    if (fun1 == fun2){
        func1();
        func2(10);
    }
   if (fun1 == print)
        fun1();
        fun11();
    }

#endif 
    return 0;
}
