#pragma once

#include <SFML/Graphics.hpp>
#include <sstream>
#include <iostream>
#include "DEFINITIONS.hpp"
#include "StateGame.hpp"
#include "State.hpp"
#include "Game.hpp"
#include "Level.hpp"

namespace Minesweeper
{
	struct GameData;

	class StateMainMenu : public State
	{
	public:
		StateMainMenu(const std::shared_ptr<GameData>& data);

		void Init() override;
		void HandleInput() override;
		void Update() override;
		void Draw() override;

	private:
		std::shared_ptr<GameData> _data;

		sf::Sprite _logo;
		sf::Sprite _easyButton;
		sf::Sprite _mediumButton;
		sf::Sprite _hardButton;
	};
}