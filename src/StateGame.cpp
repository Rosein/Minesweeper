#include "../include/StateGame.hpp"


namespace Minesweeper
{
	StateGame::StateGame(const std::shared_ptr<GameData>& data, Level level) : _data(data), _level(level)
	{	
		switch(level)
		{
			case Level::EASY:
				_board = std::make_shared<Board>(EASY_X, EASY_Y, EASY_BOMBS_RATIO);
				break;
			case Level::MEDIUM:
				_board = std::make_shared<Board>(MEDIUM_X, MEDIUM_Y, MEDIUM_BOMBS_RATIO);
				break;
			case Level::HARD:
				_board = std::make_shared<Board>(HARD_X, HARD_Y, HARD_BOMBS_RATIO);
				break;
		}
	}

	void StateGame::Init()
	{
		_headN.setTexture(_data->assets.LoadAndGetTexture(HEAD_GAME_FILEPATH));
		_headW.setTexture(_data->assets.LoadAndGetTexture(HEAD_WON_FILEPATH));
		_headL.setTexture(_data->assets.LoadAndGetTexture(HEAD_LOST_FILEPATH));
		_tiles.setTexture(_data->assets.LoadAndGetTexture(TILES_FILEPATH));
		_textBckgPoints.setTexture(_data->assets.LoadAndGetTexture(TEXT_BACKGROUND_FILEPATH));
		_textBckgTime.setTexture(_data->assets.LoadAndGetTexture(TEXT_BACKGROUND_FILEPATH));
		_bombsCounterText.setFont(_data->assets.LoadAndGetFont(CALCULATOR_FONT_FILEPATH));
		_timeCounterText.setFont(_data->assets.LoadAndGetFont(CALCULATOR_FONT_FILEPATH));

		_headN.setPosition(((_data->window).getSize().x / 2) - _headN.getGlobalBounds().width/2, 10);
		_headL.setPosition(((_data->window).getSize().x / 2) - _headL.getGlobalBounds().width/2, 10);
		_headW.setPosition(((_data->window).getSize().x / 2) - _headW.getGlobalBounds().width/2, 10);
		_textBckgPoints.setPosition(TILE_SIZE*0.7, TILE_SIZE*0.7);
		_textBckgTime  .setPosition((_data->window).getSize().x - TILE_SIZE*3.5, TILE_SIZE*0.7);
		_bombsCounterText.setCharacterSize(TILE_SIZE * 1.56);
		_timeCounterText .setCharacterSize(TILE_SIZE * 1.56);
		_bombsCounterText.setFillColor(sf::Color::Red);
		_timeCounterText .setFillColor(sf::Color::Red);
		_bombsCounterText.setPosition(TILE_SIZE*0.8,TILE_SIZE*0.5);
		_timeCounterText .setPosition((_data->window).getSize().x - TILE_SIZE*3.4, TILE_SIZE*0.5);
		_bombs = _board -> getNoOfBombs();	
	}

	void StateGame::HandleInput()
	{
		sf::Event event;
		sf::Vector2i pos;
		while (_data->window.pollEvent(event))
		{
			pos = _data -> input.GetMousePosition(_data -> window);
			int x = pos.x/TILE_SIZE +1;
			int y = pos.y/TILE_SIZE -2;
			if (sf::Event::Closed == event.type)
			{
				_data->window.close();
			}
			if(_data -> input.IsSpriteClicked(_headN, sf::Mouse::Left, _data -> window))
			{
				_board -> boardReset();
				_bombs = _board -> getNoOfBombs();
				_timer.restart();
				_game = true;
			}
                
			if(event.type == sf::Event::MouseButtonPressed && y > 0 && _game == true)
			{
				Point p = {x, y};
				if (event.mouseButton.button == sf::Mouse::Left)
				{					
					if(_board -> getFieldInfo(p) != 0 && _board -> getVisibleFieldInfo(p) != 11)
					{
						_board -> setVisibleField(p, _board -> getFieldInfo(p));
						if(_board -> getFieldInfo(p) == 9)
							_game = false;
					}
					else if(_board -> getFieldInfo(p) == 0 && _board -> getVisibleFieldInfo(p) != 11)
						_board -> displayMultipleFields(p);       
				} 
				if (event.mouseButton.button == sf::Mouse::Right) 
				{
					if(_board -> getVisibleFieldInfo(p) == 10)
					{
						_board -> setVisibleField(p, 11);               
						_bombs--;
					}
					else if(_board -> getVisibleFieldInfo(p) == 11)
					{
						_board -> setVisibleField(p, 10);
						_bombs++;
					}
				}
			}
		}
	}

	void StateGame::Update()
	{
		if(_board -> checkIfWon() && _game == true)
		{
            _game = false;
			BestScore b(_timeScore, _level);
			_data->machine.AddState(std::make_unique<StateBestScore>(_data, _timeScore, b), false);
		}
		_bombsCounter.str("");
		_bombsCounter << std::setfill('0') << std::setw(3) << _bombs << std::endl;
		_bombsCounterText.setString(_bombsCounter.str());
		if(_game)
		{
			_timeScore = _timer.getTime();
		}
		_timeCounter.str("");
		_timeCounter << std::setfill('0') << std::setw(3) << _timeScore << std::endl;
		_timeCounterText.setString(_timeCounter.str());
	}

	void StateGame::Draw()
	{
		_data->window.clear(sf::Color(192, 192, 192, 255));

		_data->window.draw(_textBckgPoints);
		_data->window.draw(_textBckgTime);
		_data->window.draw(_bombsCounterText);
		_data->window.draw(_timeCounterText);

		for (int i = 1; i <= _board -> getFieldSize().width; i++)
			for (int j = 1; j <= _board -> getFieldSize().height; j++)
			{
				Point p = {i, j};
				_tiles.setTextureRect(sf::IntRect(_board -> getVisibleFieldInfo(p)*TILE_SIZE, 0, TILE_SIZE, TILE_SIZE));
				_tiles.setPosition((i-1)*TILE_SIZE, (j+2)*TILE_SIZE);
				_data->window.draw(_tiles);
			}
		if(_game)
			_data->window.draw(_headN);
		else if (_board -> checkIfWon())
			_data->window.draw(_headW);
		else
			_data->window.draw(_headL);
		_data->window.display();
	}
}