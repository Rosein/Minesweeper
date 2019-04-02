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