#include "../include/Board.hpp"
#include <iostream>

Board::Board(int width, int height) : _y(height), _x(width)
{
    _board.resize(_x+2);
    for_each(begin(_board), end(_board), [&](std::vector<int> &v){v.resize(_y+2, 0);});
    _visibleBoard.resize(_x+2);
    for_each(begin(_visibleBoard), end(_visibleBoard), [&](std::vector<int> &v){v.resize(_y+2, 10);});
    fillField();
}

int Board::getFieldInfo(int x, int y)
{
    if( ( x <= _x && x > 0 ) && ( y <= _y && y > 0 ) )
        return _board[x][y];
    else return -1;
}

int Board::getVisibleFieldInfo(int x, int y)
{
    if( ( x <= _x && x > 0 ) && ( y <= _y && y > 0 ) )
        return _visibleBoard[x][y];
    else return -1;
}

 void Board::setVisibleField(int x, int y, int val)
 {
     _visibleBoard[x][y] = val;
 }

std::pair <int, int>  Board::getFieldSize()
{
    return std::make_pair(_x, _y);
}

void Board::fillField()
{
    int bombsAmount = _x*_y *0.16;
    srand(time(0));
    for(int i = 0; i < bombsAmount; i++)
    {
        int x = (rand() %_x)+1;
        int y = (rand() %_y)+1;
        if (_board[x][y] == 0) {_board[x][y] = 9;}
        else i--;
    }
    for(int i=1; i<=_x; i++)
        for(int j=1; j<=_y; j++)
            _board[i][j] = checkSurrounding(i, j);
}

int Board::checkSurrounding(int x, int y)
{
    if(_board[x][y] == 9) return 9;
    int count = 0;
    for(int i = x-1; i<=x+1; i++)
        for(int j = y-1; j<=y+1; j++)
            if (_board[i][j] == 9)
                count++;
    return count;
}

void Board::shoot(int x, int y)
{
    if( ( x <= _y && x > 0 ) && ( y <= _x && y > 0 ) )
        if(_visibleBoard[x][y] == 8)
           _visibleBoard[x][y] = _board[x][y];
}
