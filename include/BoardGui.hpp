#pragma once

#include "Board.hpp"
#include <vector>
#include <algorithm>
#include <random>
#include <SFML/Graphics.hpp>
#include <sstream>
#include <iomanip>

class BoardGui
{
    void displayField(sf::RenderWindow& window, std::pair<int, int> fSize, Board& board, int tileSize, sf::Sprite s, int bombs);
    void alert(std::string text, bool& game);
    void displayBombsCounter(sf::RenderWindow& app, int bombs);
public:
    BoardGui(Board& board);
};