#pragma once

#include <memory>
#include <string>
#include <SFML/Graphics.hpp>
#include "MachineOfStates.hpp"
#include "ManagerAssets.hpp"
#include "ManagerInput.hpp"
#include "StateMainMenu.hpp"

namespace Minesweeper
{
	struct GameData
	{
		MachineOfStates machine;
		sf::RenderWindow window;
		ManagerAssets assets;
		ManagerInput input;
	};

	class Game
	{
	public:
		Game(int width, int height, std::string title);

	private:
		std::shared_ptr<GameData> _data = std::make_shared<GameData>();

		void Run();
	};
}