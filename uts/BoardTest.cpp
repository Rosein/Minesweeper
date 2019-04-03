#include "gtest/gtest.h"
#include "../include/Board.hpp"

class BoardTest : public ::testing::Test
{
    
public:
    Board board{10,12};
};


TEST_F(BoardTest, getVisibleFieldInfoExpect10AtCorrectInput)
{
    EXPECT_EQ(10, board.getVisibleFieldInfo(1,1));
    EXPECT_EQ(10, board.getVisibleFieldInfo(10,12));
    EXPECT_EQ(-1, board.getVisibleFieldInfo(0,0));
    EXPECT_EQ(10, board.getVisibleFieldInfo(1,1));
    EXPECT_EQ(-1, board.getVisibleFieldInfo(11,13));
    EXPECT_EQ(10, board.getVisibleFieldInfo(5,5));
}

TEST_F(BoardTest, getFieldSizeExpect10and12)
{
    EXPECT_EQ(std::make_pair(10,12), board.getFieldSize());
}

TEST_F(BoardTest, checkIfComputerFilledTheBoardWith16procBombs)
{
    Board board2{10,12};
    int i=0;
    auto size = board2.getFieldSize();
    for(int j=1; j<=size.first; j++)
        for(int k=1; k<=size.second; k++)
            if (board2.getFieldInfo(j, k) == 9)
                i++;
    EXPECT_EQ(19, i);
}

TEST_F(BoardTest, setVisibleFiedExpectGetTheSame)
{
    board.setVisibleField(1,1,5);
    EXPECT_EQ(5, board.getVisibleFieldInfo(1,1));
}

TEST_F(BoardTest, displayMultipleFieldsDisplaysThem)
{
    auto size = board.getFieldSize();
    for(int j=1; j<=size.first; j++)
        for(int k=1; k<=size.second; k++)
        {
            if(board.getFieldInfo(j,k) == 0)
            {
                board.displayMultipleFields(j, k);
                EXPECT_GT(10, board.getVisibleFieldInfo(j+1, k+1));
                EXPECT_GT(10, board.getVisibleFieldInfo(j+1, k-1));
                EXPECT_GT(10, board.getVisibleFieldInfo(j-1, k+1));
                EXPECT_GT(10, board.getVisibleFieldInfo(j-1, k-1));
                EXPECT_GT(10, board.getVisibleFieldInfo(j+1, k  ));
                EXPECT_GT(10, board.getVisibleFieldInfo(j-1, k  ));
                EXPECT_GT(10, board.getVisibleFieldInfo(j  , k+1));
                EXPECT_GT(10, board.getVisibleFieldInfo(j  , k-1));
            }

        }
}

TEST_F(BoardTest, checkIfWon)
{
    Board board2{3,3};
    EXPECT_FALSE(board2.checkIfWon());
    for(int i=1; i<=3; i++)
        for(int j=1; j<=3; j++)
            if(board2.getFieldInfo(i, j) != 9)
                board2.setVisibleField(i, j, board2.getFieldInfo(i, j));
    EXPECT_TRUE(board2.checkIfWon());
}

TEST_F(BoardTest, checkNoOfBombsExpect19)
{
    EXPECT_EQ(19, board.getNoOfBombs());
}