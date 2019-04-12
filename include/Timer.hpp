#pragma once
#include <iostream>
#include <chrono>

namespace Minesweeper
{
    class Timer
    {
        int _duration;
        std::chrono::_V2::system_clock::time_point _start;
    public:
        Timer();
        int getTime();
        void restart();
    };
}