#pragma once

#include "Board.hpp"
#include <vector>
#include <algorithm>
#include <random>
#include <SFML/Graphics.hpp>

class BoardGui
{
    void displayField(sf::RenderWindow& window, std::pair<int, int> fSize, Board& board, int tileSize, sf::Sprite s);
    void alert(std::string text, bool& game);
public:
    BoardGui(Board& board);
};