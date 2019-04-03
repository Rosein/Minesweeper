#pragma once

#include <vector>
#include <algorithm>
#include <random>

class Board
{
    int _y;
    int _x;
    int _bombs;
    std::vector<std::vector<int>> _board;
    std::vector<std::vector<int>> _visibleBoard;
    int numberFields(int x, int y);
    void fillField();
    void showSurroundingOfEmptyField(std::vector<std::pair<int, int>>& emptyFields);
    void findWholeSurroundingOfEmpty(int x, int y, std::vector<std::pair<int, int>>& emptyFields);
public:
    Board(int width, int height);
    std::pair <int, int> getFieldSize();
    int getNoOfBombs();
    int getFieldInfo(int x, int y);
    int getVisibleFieldInfo(int x, int y);
    void setVisibleField(int x, int y, int val);
    void displayMultipleFields(int x, int y);
    bool checkIfWon();
};
    