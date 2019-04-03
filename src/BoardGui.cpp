#include "../include/BoardGui.hpp"
#include <iostream>

BoardGui::BoardGui(Board& board)
{
    int tileSize = 50;
    auto fSize = board.getFieldSize();
    sf::RenderWindow window( sf::VideoMode( (fSize.first)*tileSize, (fSize.second+3)*tileSize), "Minesweeper" );
    bool game = true;
    int bombs = board.getNoOfBombs();


    sf::Texture background;
    background.loadFromFile("images/background.jpg");
    sf::Sprite sBackground(background);
    sf::Texture t;
    t.loadFromFile("images/tiles.jpg");
    sf::Sprite s(t);
    sf::Event e;

    displayField(window, fSize, board, tileSize, s, bombs);
    while( window.isOpen() && game )
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
                    {
                        board.setVisibleField(x, y, 11);               
                        bombs--;
                    }
                    else if(board.getVisibleFieldInfo(x, y) == 11)
                    {
                        board.setVisibleField(x, y, 10);
                        bombs++;
                    }
                }
            displayField(window, fSize, board, tileSize, s, bombs);       
            if(board.getVisibleFieldInfo(x, y) == 9)
                alert("You lost!", game);
            else if(board.checkIfWon())
                alert("You won!", game);
            }          
        } 
    }

}

void BoardGui::displayField(sf::RenderWindow& window, std::pair<int, int> fSize, Board& board, int tileSize, sf::Sprite s, int bombs)
{
    window.clear(sf::Color(192, 192, 192, 255));
    for (int i=1; i<=fSize.first; i++)
        for (int j=1; j<=fSize.second; j++)
        {
            s.setTextureRect(sf::IntRect(board.getVisibleFieldInfo(i, j)*tileSize, 0, tileSize, tileSize));
            s.setPosition((i-1)*tileSize, (j+2)*tileSize);
            window.draw(s);
        }
    displayBombsCounter(window, bombs);
    window.display();
}

void BoardGui::alert(std::string text, bool& game)
{
    sf::RenderWindow alrt(sf::VideoMode(200, 200), text);
    while (alrt.isOpen())
    {
        sf::Texture t;
        if(text == "You won!")
            t.loadFromFile("images/youWon.jpg");
        else if(text == "You lost!")
            t.loadFromFile("images/youLost.jpg");
        sf::Sprite s(t);

        while (alrt.isOpen())
        {
            alrt.clear(sf::Color::White);
            alrt.draw(s);
            sf::Event e;
            while (alrt.pollEvent(e))
            {
                if (e.type == sf::Event::Closed)
                    alrt.close();
            }
            alrt.display();
        }
        game = false;
    }
}

void BoardGui::displayBombsCounter(sf::RenderWindow& window, int bombs)
{
    window.pushGLStates();

    sf::Texture textBckg;
    textBckg.loadFromFile("images/numBckg.jpg");
    sf::Sprite sTextBckg(textBckg);
    sTextBckg.setPosition(30, 30);
    window.draw(sTextBckg);

    sf::Font font;
    if (!font.loadFromFile("fonts/calcFont.otf"))
        std::cout << "Error loading font\n" ;
    std::ostringstream ss;
    ss << std::setfill('0') << std::setw(3) << bombs << std::endl;
    sf::Text atext;
    atext.setFont(font);
    atext.setCharacterSize(95);
    atext.setFillColor(sf::Color::Red);
    atext.setPosition(33,16);
    atext.setString(ss.str());

    window.draw(atext);
    window.popGLStates();
}