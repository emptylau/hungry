#include <iostream>
#include <iomanip>
#include <ctime>
#include <chrono>
 
int main()
{
    using namespace std::chrono;

    system_clock::time_point now = system_clock::now();
    std::time_t last = system_clock::to_time_t(now - std::chrono::hours(24));
    std::time_t next= system_clock::to_time_t(now - std::chrono::hours(24));
    std::cout << "One day ago, the time was "<< std::put_time(std::localtime(&last), "%F %T") << '\n';
    std::cout << "Next day, the time was "<< std::put_time(std::localtime(&next), "%F %T") << '\n'; 
}
