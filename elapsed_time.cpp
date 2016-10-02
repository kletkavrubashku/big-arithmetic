#include "elapsed_time.h"

Timer::Timer()
{
    begin = std::clock();
}

double Timer::ElapsedTime() const
{
    return double(clock() - begin) / CLOCKS_PER_SEC;
}
