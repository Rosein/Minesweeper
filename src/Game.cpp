#include "../include/Game.hpp"


namespace Minesweeper
{
	Game::Game(int width, int height, std::string title)
	{
		_data->window.create(sf::VideoMode(width, height), title, sf::Style::Close | sf::Style::Titlebar);
		_data->window.setFramerateLimit(FRAMERATE_LIMIT);
		_data->machine.AddState(StateRef(std::make_unique<StateMainMenu>(_data)));

		Run();
	}

	void Game::Run()
	{
		while (_data->window.isOpen())
		{
			_data->machine.ProcessStateChanges();
			_data->machine.GetActiveState()-> HandleInput();
			_data->machine.GetActiveState()-> Update();
			_data->machine.GetActiveState()-> Draw();
		}
	}
}