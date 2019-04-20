#pragma once

#include <vector>
#include <algorithm>
#include <random>
#include "Point.hpp"

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
        int numberFields(Point p);
        void fillField();
        void showSurroundingOfEmptyField(std::vector<Point>& emptyFields);
        void findWholeSurroundingOfEmpty(Point p, std::vector<Point>& emptyFields);
    public:
        Board(int width, int height, float bombsFactor);
        BSize getFieldSize() const;
        int getNoOfBombs() const;
        int getFieldInfo(Point p) const;
        int getVisibleFieldInfo(Point p) const;
        void setVisibleField(Point p, int val);
        void displayMultipleFields(Point p);
        bool checkIfWon() const;
        void boardReset();
    };
}
    