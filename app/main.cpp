#include "../include/Board.hpp"
#include "../include/BoardGui.hpp"

#include <iostream>

int main(int argc, char* argv[])
{
    srand(time(0));
    Board myBoard(10, 12);
    BoardGui game(myBoard);
    return 0;
}