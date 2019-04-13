#include "../include/StateMainMenu.hpp"


namespace Minesweeper
{
	StateMainMenu::StateMainMenu(const std::shared_ptr<GameData>& data) : _data(data)
	{

	}

	void StateMainMenu::Init()
	{
		_logo.setTexture  (_data->assets.LoadAndGetTexture(LOGO_FILEPATH));
		_easyButton.setTexture  (_data->assets.LoadAndGetTexture(EASY_BUTTON_FILEPATH));
		_mediumButton.setTexture(_data->assets.LoadAndGetTexture(MEDIUM_BUTTON_FILEPATH));
		_hardButton.setTexture  (_data->assets.LoadAndGetTexture(HARD_BUTTON_FILEPATH));

		_logo.setPosition  ((_data -> window.getSize().x) / 2 - (_logo.getGlobalBounds().width / 2), 30);
		_easyButton.setPosition  ((_data -> window.getSize().x) / 2 - (_easyButton.getGlobalBounds().width / 2), 200);
		_mediumButton.setPosition((_data -> window.getSize().x) / 2 - (_mediumButton.getGlobalBounds().width / 2), 280);
		_hardButton.setPosition  ((_data -> window.getSize().x) / 2 - (_hardButton.getGlobalBounds().width / 2), 360);
	}

	void StateMainMenu::HandleInput()
	{
		sf::Event event;

		while (_data->window.pollEvent(event))
		{
			if (sf::Event::Closed == event.type)
			{
				_data->window.close();
			}

			if (_data->input.IsSpriteClicked(_easyButton, sf::Mouse::Left, _data->window))
			{
				_data->window.create(sf::VideoMode(EASY_X * TILE_SIZE, (EASY_Y + HEIGHT_TOP_PANEL) * TILE_SIZE),
													TITLE, sf::Style::Close | sf::Style::Titlebar);
				_data->window.setFramerateLimit(FRAMERATE_LIMIT);
				_data->machine.AddState(std::make_unique<StateGame>(_data, Level::EASY ), true);
			}
			if (_data->input.IsSpriteClicked(_mediumButton, sf::Mouse::Left, _data->window))
			{
				_data->window.create(sf::VideoMode(MEDIUM_X * TILE_SIZE, (MEDIUM_Y + HEIGHT_TOP_PANEL) * TILE_SIZE),
													TITLE, sf::Style::Close | sf::Style::Titlebar);
				_data->window.setFramerateLimit(FRAMERATE_LIMIT);
				_data->machine.AddState(std::make_unique<StateGame>(_data, Level::MEDIUM ), true);
			}
			if (_data->input.IsSpriteClicked(_hardButton, sf::Mouse::Left, _data->window))
			{
				_data->window.create(sf::VideoMode(HARD_X * TILE_SIZE, (HARD_Y + HEIGHT_TOP_PANEL) * TILE_SIZE),
													TITLE, sf::Style::Close | sf::Style::Titlebar);
				_data->window.setFramerateLimit(FRAMERATE_LIMIT);
				_data->machine.AddState(std::make_unique<StateGame>(_data, Level::HARD ), true);
			}
		}
	}

	void StateMainMenu::Update()
	{
		
	}

	void StateMainMenu::Draw()
	{
		_data->window.clear(sf::Color(192, 192, 192, 255));

		_data->window.draw(_logo);
		_data->window.draw(_easyButton);
		_data->window.draw(_mediumButton);
		_data->window.draw(_hardButton);

		_data->window.display();
	}
}