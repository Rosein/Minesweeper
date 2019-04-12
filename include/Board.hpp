#pragma once

#include <vector>
#include <algorithm>
#include <random>

namespace Minesweeper
{
    class Board
    {
        int _x;
        int _y;
        int _bombs;
        float _bombsFactor;
        std::vector<std::vector<int>> _board;
        std::vector<std::vector<int>> _visibleBoard;
        int numberFields(int x, int y);
        void fillField();
        void showSurroundingOfEmptyField(std::vector<std::pair<int, int>>& emptyFields);
        void findWholeSurroundingOfEmpty(int x, int y, std::vector<std::pair<int, int>>& emptyFields);
    public:
        Board(int width, int height, float bombsFactor);
        std::pair <int, int> getFieldSize() const;
        int getNoOfBombs() const;
        int getFieldInfo(int x, int y) const;
        int getVisibleFieldInfo(int x, int y) const;
        void setVisibleField(int x, int y, int val);
        void displayMultipleFields(int x, int y);
        bool checkIfWon() const;
        void boardReset();
    };
}
    