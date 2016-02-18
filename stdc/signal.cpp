#include <csignal>
#include <iostream>
#include <ctime>
#include <unistd.h>

void signal_handler(int param);

int main(int argc, char* argv[])
{

    signal(SIGINT, signal_handler); // ctrl + c
    signal(SIGABRT, signal_handler);
    signal(SIGTERM, signal_handler);
    //signal(SIGKILL, signal_handler); 不可以接受的信号
    signal(SIGTSTP, signal_handler); // ctrl + z
    signal(SIGQUIT, signal_handler); // ctrl + \

    //raise(SIGINT);

    while(true){
        sleep(1);
    }

    return 0;
}

void signal_handler(int param)
{
    std::cout << "signal " << param << std::endl;
}
