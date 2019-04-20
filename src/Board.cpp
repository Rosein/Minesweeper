#include "../include/Board.hpp"
#include <iostream>

namespace Minesweeper
{
    Board::Board(int width, int height, float bombsFactor) : _x(width), _y(height), _bombsFactor(bombsFactor)
    {
        _board.resize(_x+2);
        std::for_each(begin(_board), end(_board), [&](std::vector<int> &v){v.resize(_y+2, 0);});
        _visibleBoard.resize(_x+2);
        std::for_each(begin(_visibleBoard), end(_visibleBoard), [&](std::vector<int> &v){v.resize(_y+2, 10);});
        fillField();
    }

    int Board::getFieldInfo(Point p) const
    {
        if( ( p.x <= _x && p.x > 0 ) && ( p.y <= _y && p.y > 0 ) )
            return _board[p.x][p.y];
        else return -1;
    }

    int Board::getVisibleFieldInfo(Point p) const
    {
        if( ( p.x <= _x && p.x > 0 ) && ( p.y <= _y && p.y > 0 ) )
            return _visibleBoard[p.x][p.y];
        else return -1;
    }

    void Board::setVisibleField(Point p, int val)
    {
        _visibleBoard[p.x][p.y] = val;
    }

    BSize Board::getFieldSize() const
    {
        BSize boardSize = {_x, _y};
        return boardSize;
    }

    int Board::getNoOfBombs() const
    {
        return _bombs;
    }

    void Board::fillField()
    {
        _bombs = _x*_y *_bombsFactor;
        srand(time(0));
        for(int i = 0; i < _bombs; i++)
        {
            int x = (rand() %_x)+1;
            int y = (rand() %_y)+1;
            if (_board[x][y] == 0) {_board[x][y] = 9;}
            else i--;
        }
        for(int i=1; i<=_x; i++)
            for(int j=1; j<=_y; j++)
            {
                Point p = {i, j};
                _board[i][j] = numberFields(p);
            }
    }

    int Board::numberFields(Point p)
    {
        if(_board[p.x][p.y] == 9) return 9;
        int count = 0;
        for(int i = p.x-1; i<=p.x+1; i++)
            for(int j = p.y-1; j<=p.y+1; j++)
                if (_board[i][j] == 9)
                    count++;
        return count;
    }

    void Board::displayMultipleFields(Point p)
    {
        std::vector<Point> emptyFields;
        findWholeSurroundingOfEmpty(p, emptyFields);
        showSurroundingOfEmptyField(emptyFields);
    }

    void Board::findWholeSurroundingOfEmpty(Point p, std::vector<Point>& emptyFields)
    {
        if( ( p.x <= _x && p.x > 0 ) && ( p.y <= _y && p.y > 0 ) )
            for(int i = p.x-1; i<=p.x+1; i++)
                for(int j = p.y-1; j<=p.y+1; j++)
                {
                    Point pt = {i, j};
                    auto it = std::find (begin(emptyFields), end(emptyFields), pt);
                    if(it == end(emptyFields))
                    {
                        emptyFields.push_back(pt); 
                        if(_board[i][j] == 0)
                            findWholeSurroundingOfEmpty(pt, emptyFields);
                    }
                }
    }

    void Board::showSurroundingOfEmptyField(std::vector<Point>& emptyFields)
    {
        for(auto elem : emptyFields)
        {
            int x = elem.x;
            int y = elem.y;
            _visibleBoard[x][y] = _board[x][y];
        }
    }

    bool Board::checkIfWon() const
    {
        for(int i=1; i<=_x; i++)
            for(int j=1; j<=_y; j++)
                if(_board[i][j] !=9)
                    if(_board[i][j] != _visibleBoard[i][j])
                        return false;
        return true;
    }

    void Board::boardReset()
    {
        std::for_each(begin(_board), end(_board), [&](std::vector<int> &v){ std::fill(v.begin(), v.end(), 0); });
        std::for_each(begin(_visibleBoard), end(_visibleBoard), [&](std::vector<int> &v){ std::fill(v.begin(), v.end(), 10); });
        fillField();
    }
}