#include "gtest/gtest.h"
#include "../include/Board.hpp"
#include "../include/Point.hpp"

class BoardTest : public ::testing::Test
{
    
public:
    Minesweeper::Board board{10, 12, 0.16};
};


TEST_F(BoardTest, getVisibleFieldInfoExpect10AtCorrectInput)
{
    Minesweeper::Point p1x1   = {1 , 1 };
    Minesweeper::Point p10x12 = {10, 12};
    Minesweeper::Point p0x0   = {0 , 0 };
    Minesweeper::Point p11x13 = {11, 13};
    Minesweeper::Point p5x5   = {5 , 5 };
    EXPECT_EQ(10, board.getVisibleFieldInfo(p1x1  ));
    EXPECT_EQ(10, board.getVisibleFieldInfo(p10x12));
    EXPECT_EQ(-1, board.getVisibleFieldInfo(p0x0  ));
    EXPECT_EQ(-1, board.getVisibleFieldInfo(p11x13));
    EXPECT_EQ(10, board.getVisibleFieldInfo(p5x5  ));
}

TEST_F(BoardTest, getFieldSizeExpect10and12)
{
    EXPECT_EQ(10, board.getFieldSize().width);
    EXPECT_EQ(12, board.getFieldSize().height);
}

TEST_F(BoardTest, checkIfComputerFilledTheBoardWith16procBombs)
{
    int i=0;
    Minesweeper::Point p;
    auto size = board.getFieldSize();
    for(int j=1; j<=size.width; j++)
        for(int k=1; k<=size.height; k++)
        {
            p = {j, k};
            if (board.getFieldInfo(p) == 9)
                i++;
        }
    EXPECT_EQ(19, i);
}

TEST_F(BoardTest, setVisibleFiedExpectGetTheSame)
{
    Minesweeper::Point p = {1, 1};
    board.setVisibleField(p, 5);
    EXPECT_EQ(5, board.getVisibleFieldInfo(p));
}

TEST_F(BoardTest, displayMultipleFieldsDisplaysThem)
{
    auto size = board.getFieldSize();
    Minesweeper::Point p;
    for(int j=1; j<=size.width; j++)
        for(int k=1; k<=size.height; k++)
        {
            p = {j, k};
            if(board.getFieldInfo(p) == 0)
            {
                board.displayMultipleFields(p);
                for(int m = j-1; m <= j+1; m++)
                    for(int n = k-1; n <= k+1; n++)
                    {
                        p = {m, n};
                        EXPECT_GT(10, board.getVisibleFieldInfo(p));
                    }
            }

        }
}

TEST_F(BoardTest, checkIfWon)
{
    Minesweeper::Board board2{3, 3, 0.2};
    Minesweeper::Point p;
    EXPECT_FALSE(board2.checkIfWon());
    for(int i=1; i<=3; i++)
        for(int j=1; j<=3; j++)
        {
            p = {i, j};
            if(board2.getFieldInfo(p) != 9)
                board2.setVisibleField(p, board2.getFieldInfo(p));
        }
    EXPECT_TRUE(board2.checkIfWon());
}

TEST_F(BoardTest, checkNoOfBombsExpect19)
{
    EXPECT_EQ(19, board.getNoOfBombs());
}