#include "../include/Timer.hpp"

namespace Minesweeper
{
    Timer::Timer()
    {
        _start = std::chrono::high_resolution_clock::now();
    }

    int Timer::getTime()
    {
        auto _end = std::chrono::high_resolution_clock::now();
        return std::chrono::duration<double, std::milli>(_end - _start).count()/1000;
    }

    void Timer::restart()
    {
        _start = std::chrono::high_resolution_clock::now();
    }
}