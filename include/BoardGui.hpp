#pragma once

#include "Board.hpp"
#include <vector>
#include <algorithm>
#include <random>
#include <SFML/Graphics.hpp>

class BoardGui
{
    void displayField(sf::RenderWindow& window, std::pair<int, int> fSize, Board& board, int tileSize, sf::Sprite s);
public:
    BoardGui(Board& board);
};