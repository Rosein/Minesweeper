#pragma once
#include <cstdio>
#include <ctime>
#include <iostream>

class Timer
{
    int _duration;
    std::clock_t _start;
public:
    Timer();
    int getTime();
};