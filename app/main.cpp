#include "../include/Game.hpp"
#include "../include/DEFINITIONS.hpp"

int main()
{
	Minesweeper::Game(10*TILE_SIZE, 13*TILE_SIZE, "Minesweeper");

	return 0;
}