#include "../include/BoardGui.hpp"
#include <iostream>

BoardGui::BoardGui(Board& board)
{
    Timer timer;
    int timeScore;
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
    sf::Texture tHeadN;
    tHeadN.loadFromFile("images/youPlay.jpg");
    sf::Sprite sHeadN(tHeadN);
    sHeadN.setPosition(windowWidth/2-60, 15);
    sf::Texture tHeadL;
    tHeadL.loadFromFile("images/youLost.jpg");
    sf::Sprite sHeadL(tHeadL);
    sHeadL.setPosition(windowWidth/2-60, 15);
    sf::Texture tHeadW;
    tHeadW.loadFromFile("images/youWon.jpg");
    sf::Sprite sHeadW(tHeadW);
    sHeadW.setPosition(windowWidth/2-60, 15);
    sf::Texture textBckg;
    textBckg.loadFromFile("images/numBckg.jpg");
    sf::Sprite sTextBckg(textBckg);
    sf::Font font;
    if (!font.loadFromFile("fonts/calcFont.otf"))
        std::cout << "Error loading font\n" ;

    sf::Event e;
    while( window.isOpen())
    {
        window.clear(sf::Color(192, 192, 192, 255));
        sf::Vector2i pos = sf::Mouse::getPosition(window);
        sf::Vector2f mousePosF( static_cast<float>( pos.x ), static_cast<float>( pos.y ) );
        int x = pos.x/tileSize +1;
        int y = pos.y/tileSize -2;
        
        while(window.pollEvent(e))
        {
            
            if (e.type == sf::Event::Closed)
                window.close();

            if (e.type == sf::Event::MouseButtonPressed)
            {
                if (e.mouseButton.button == sf::Mouse::Left)
                    if (sHeadN.getGlobalBounds().contains(mousePosF))
                    {
                        board.boardReset();
                        bombs = board.getNoOfBombs();
                        timer.restart();
                        game = true;
                    }
                
                if(game && y > 0)
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
        } 
        window.draw(sHeadN);
        if(board.getVisibleFieldInfo(x, y) == 9 || !game)
        {
            window.draw(sHeadL);
            game = false;
        }
        if(board.checkIfWon())
        {
            window.draw(sHeadW);
            game = false;
        }

        displayField(window, fSize, board, tileSize, s);  
        displayTopPanel(window, bombs, windowWidth, timer, timeScore, game, sTextBckg, font);
        window.display();     
    }
}


void BoardGui::displayField(sf::RenderWindow& window, std::pair<int, int> fSize, Board& board, int tileSize, sf::Sprite s)
{  
    for (int i=1; i<=fSize.first; i++)
        for (int j=1; j<=fSize.second; j++)
        {
            s.setTextureRect(sf::IntRect(board.getVisibleFieldInfo(i, j)*tileSize, 0, tileSize, tileSize));
            s.setPosition((i-1)*tileSize, (j+2)*tileSize);
            window.draw(s);
        }
}


void BoardGui::displayTopPanel(sf::RenderWindow& window, int bombs, int windowWidth, Timer& timer, int& timeScore, bool game, sf::Sprite& sTextBckg, sf::Font& font)
{
    window.pushGLStates();

    
    sTextBckg.setPosition(35, 35);
    window.draw(sTextBckg);
    sTextBckg.setPosition(windowWidth - 180, 35);
    window.draw(sTextBckg);

    std::ostringstream bombsCounter;
    bombsCounter << std::setfill('0') << std::setw(3) << bombs << std::endl;
    sf::Text bombsCounterText;
    bombsCounterText.setFont(font);
    bombsCounterText.setCharacterSize(78);
    bombsCounterText.setFillColor(sf::Color::Red);
    bombsCounterText.setPosition(40,25);
    bombsCounterText.setString(bombsCounter.str());

    std::ostringstream timeCounter;
    if(game)
    {
        timeScore = timer.getTime();
    }
    timeCounter << std::setfill('0') << std::setw(3) << timeScore << std::endl;
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