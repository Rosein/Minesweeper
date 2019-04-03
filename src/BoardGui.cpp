#include "../include/BoardGui.hpp"
#include <iostream>

BoardGui::BoardGui(Board& board)
{
    Timer timer;
    int tileSize = 50;
    auto fSize = board.getFieldSize();
    int windowWidth = (fSize.first)*tileSize;
    int windowHeight = (fSize.second+3)*tileSize;
    sf::RenderWindow window( sf::VideoMode( windowWidth, windowHeight), "Minesweeper" );
    window.setFramerateLimit(10);
    bool game = true;
    int bombs = board.getNoOfBombs();

    sf::Texture t;
    t.loadFromFile("images/tiles.jpg");
    sf::Sprite s(t);
    sf::Event e;
    displayField(window, fSize, board, tileSize, s, bombs, windowWidth, timer);
    while( window.isOpen() && game )
    {
        sf::Vector2i pos = sf::Mouse::getPosition(window);
        int x = pos.x/tileSize +1;
        int y = pos.y/tileSize -2;
        while(window.pollEvent(e))
        {
            
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
            }          
        } 
        displayField(window, fSize, board, tileSize, s, bombs, windowWidth, timer);       
        if(board.getVisibleFieldInfo(x, y) == 9)
            alert("You lost!", game);
        else if(board.checkIfWon())
            alert("You won!", game);
    }

}

void BoardGui::displayField(sf::RenderWindow& window, std::pair<int, int> fSize, Board& board, int tileSize, sf::Sprite s, int bombs, int windowWidth, Timer& timer)
{
    window.clear(sf::Color(192, 192, 192, 255));
    for (int i=1; i<=fSize.first; i++)
        for (int j=1; j<=fSize.second; j++)
        {
            s.setTextureRect(sf::IntRect(board.getVisibleFieldInfo(i, j)*tileSize, 0, tileSize, tileSize));
            s.setPosition((i-1)*tileSize, (j+2)*tileSize);
            window.draw(s);
        }
    displayBombsCounter(window, bombs, windowWidth, timer);
    window.display();
}

void BoardGui::alert(std::string text, bool& game)
{
    sf::RenderWindow alrt(sf::VideoMode(200, 200), text);
    alrt.setFramerateLimit(1);
    sf::Texture t;
    if(text == "You won!")
        t.loadFromFile("images/youWon.jpg");
    else if(text == "You lost!")
        t.loadFromFile("images/youLost.jpg");
    sf::Sprite s(t);
    alrt.clear(sf::Color::White);
    alrt.draw(s);
    sf::Event e;
    alrt.display();
    while (alrt.isOpen())
    {
        alrt.pollEvent(e);
        if (e.type == sf::Event::Closed)
            alrt.close();     
    }
    game = false;
}

void BoardGui::displayBombsCounter(sf::RenderWindow& window, int bombs, int windowWidth, Timer& timer)
{
    window.pushGLStates();

    sf::Texture textBckg;
    textBckg.loadFromFile("images/numBckg.jpg");
    sf::Sprite sTextBckg(textBckg);
    sTextBckg.setPosition(35, 35);
    window.draw(sTextBckg);
    sTextBckg.setPosition(windowWidth - 180, 35);
    window.draw(sTextBckg);

        sf::Font font;
    if (!font.loadFromFile("fonts/calcFont.otf"))
        std::cout << "Error loading font\n" ;
    std::ostringstream bombsCounter;
    bombsCounter << std::setfill('0') << std::setw(3) << bombs << std::endl;
    sf::Text bombsCounterText;
    bombsCounterText.setFont(font);
    bombsCounterText.setCharacterSize(78);
    bombsCounterText.setFillColor(sf::Color::Red);
    bombsCounterText.setPosition(40,25);
    bombsCounterText.setString(bombsCounter.str());

    std::ostringstream timeCounter;
    timeCounter << std::setfill('0') << std::setw(3) << timer.getTime() << std::endl;
    sf::Text timeCounterText;
    timeCounterText.setFont(font);
    timeCounterText.setCharacterSize(78);
    timeCounterText.setFillColor(sf::Color::Red);
    timeCounterText.setPosition(windowWidth - 175, 25);
    timeCounterText.setString(timeCounter.str());

    window.draw(bombsCounterText);
    window.draw(timeCounterText);
    window.popGLStates();
}