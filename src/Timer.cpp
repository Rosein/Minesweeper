#include "../include/Timer.hpp"

Timer::Timer()
{
    _start = std::clock();
}

int Timer::getTime()
{
    _duration = ( std::clock() - _start ) / (double) CLOCKS_PER_SEC *10;
    return _duration;
}