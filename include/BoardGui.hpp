#pragma once
#include "Timer.hpp"
#include "Board.hpp"
#include <vector>
#include <algorithm>
#include <random>
#include <SFML/Graphics.hpp>
#include <sstream>
#include <iomanip>

class BoardGui
{
    void displayField(sf::RenderWindow& window, std::pair<int, int> fSize, Board& board, int tileSize, sf::Sprite s);
    void alert(std::string text, bool& game);
    void displayTopPanel(sf::RenderWindow& app, int bombs, int windowWidth, Timer& timer, int& timeScore, bool game, sf::Sprite& sTextBckg, sf::Font& font);
public:
    BoardGui(Board& board);
};