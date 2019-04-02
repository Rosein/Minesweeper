#pragma once

#include <vector>
#include <algorithm>
#include <random>

class Board
{
    int _y;
    int _x;
    std::vector<std::vector<int>> _board;
    std::vector<std::vector<int>> _visibleBoard;
    int checkSurrounding(int x, int y);
    void fillField();
public:
    Board(int width, int height);
    int getFieldInfo(int x, int y);
    int getVisibleFieldInfo(int x, int y);
    void setVisibleField(int x, int y, int val);
    std::pair <int, int> getFieldSize();
    void shoot(int x, int y);
};
    