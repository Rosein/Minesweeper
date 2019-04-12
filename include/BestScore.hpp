#pragma once

#include "DEFINITIONS.hpp"
#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm> 

class BestScore
{
    std::vector<int> bestScore;
    bool changed = false;
    void init();
public:
    BestScore();
    BestScore(const int score);
    std::vector<int> getBestScores();
};