#include "../include/BoardGui.hpp"
#include <iostream>

BoardGui::BoardGui(Board& board)
{
    int tileSize = 50;
    auto fSize = board.getFieldSize();
    sf::RenderWindow window( sf::VideoMode( (fSize.first)*tileSize, (fSize.second+3)*tileSize), "Minsweeper" );


    sf::Texture background;
    background.loadFromFile("images/background.jpg");
    sf::Sprite sBackground(background);
    sf::Texture t;
    t.loadFromFile("images/tiles.jpg");
    sf::Sprite s(t);
    sf::Event e;

    displayField(window, fSize, board, tileSize, s);
    while( window.isOpen() )
    {
        while(window.pollEvent(e))
        {
            sf::Vector2i pos = sf::Mouse::getPosition(window);
            int x = pos.x/tileSize +1;
            int y = pos.y/tileSize -2;
            if (e.type == sf::Event::Closed)
                window.close();

            if (e.type == sf::Event::MouseButtonPressed)
            {
                if (e.mouseButton.button == sf::Mouse::Left)
                {
                    if(board.getFieldInfo(x, y) != 0 && board.getVisibleFieldInfo(x, y) != 11)
                        board.setVisibleField(x, y, board.getFieldInfo(x, y));
                    else if(board.getFieldInfo(x, y) == 0 && board.getVisibleFieldInfo(x, y) != 11)
                        board.displayMultipleFields(x, y);       
                } 
                if (e.mouseButton.button == sf::Mouse::Right) 
                {
                    if(board.getVisibleFieldInfo(x, y) == 10)
                        board.setVisibleField(x, y, 11);
                    
                    else if(board.getVisibleFieldInfo(x, y) == 11)
                        board.setVisibleField(x, y, 10);
                }
            displayField(window, fSize, board, tileSize, s);       
            }          
        } 
    }

}

void BoardGui::displayField(sf::RenderWindow& window, std::pair<int, int> fSize, Board& board, int tileSize, sf::Sprite s)
{
    window.clear(sf::Color(192, 192, 192, 255));
    for (int i=1; i<=fSize.first; i++)
        for (int j=1; j<=fSize.second; j++)
        {
            s.setTextureRect(sf::IntRect(board.getVisibleFieldInfo(i, j)*tileSize, 0, tileSize, tileSize));
            s.setPosition((i-1)*tileSize, (j+2)*tileSize);
            window.draw(s);
        }
    window.display();}