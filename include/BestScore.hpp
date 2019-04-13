#pragma once

#include "DEFINITIONS.hpp"
#include "Level.hpp"
#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm> 

class BestScore
{
    std::vector<int> _bestScore;
    std::string _filepath;
    bool _changed = false;
    Level _level;
    void init();
public:
    BestScore();
    BestScore(const int score, Level level);
    std::vector<int> getBestScores();
};