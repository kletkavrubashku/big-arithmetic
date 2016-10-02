# pragma once

#include <ctime>

class Timer {
public:
    Timer();

    double ElapsedTime() const;
private:
    clock_t begin;
};