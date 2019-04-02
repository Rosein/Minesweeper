#include "../include/BoardGui.hpp"
#include <iostream>

BoardGui::BoardGui(Board& board)
{
    int tileSize = 50;
    auto fSize = board.getFieldSize();
    sf::RenderWindow window( sf::VideoMode( (fSize.first+2)*tileSize, (fSize.second+2)*tileSize), "Minsweeper" );


    sf::Texture background;
    background.loadFromFile("images/background.jpg");
    sf::Sprite sBackground(background);
    sf::Texture t;
    t.loadFromFile("images/tiles.jpg");
    sf::Sprite s(t);
    sf::Event e;


    while( window.isOpen() )
    {
        sf::Vector2i pos = sf::Mouse::getPosition(window);
        int x = pos.x/tileSize;
        int y = pos.y/tileSize;
        window.pollEvent(e);

        if (e.type == sf::Event::Closed)
            window.close();

        if (e.type == sf::Event::MouseButtonPressed)
        {
            if (e.mouseButton.button == sf::Mouse::Left) 
                board.setVisibleField(x, y, board.getFieldInfo(x, y));     
            if (e.mouseButton.button == sf::Mouse::Right) 
                if(board.getVisibleFieldInfo(x, y) == 10)
                    board.setVisibleField(x, y, 11);
        }
        
        window.clear(sf::Color::White);

        for (int i=1; i<=fSize.first; i++)
            for (int j=1; j<=fSize.second; j++)
            {
                s.setTextureRect(sf::IntRect(board.getVisibleFieldInfo(i, j)*tileSize, 0, tileSize, tileSize));
                s.setPosition(i*tileSize, j*tileSize);
                window.draw(s);
            }
        window.display();
    }

}