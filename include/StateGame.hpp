#pragma once

#include <SFML/Graphics.hpp>
#include <sstream>
#include <iostream>
#include <iomanip>
#include "DEFINITIONS.hpp"
#include "State.hpp"
#include "Game.hpp"
#include "Board.hpp"
#include "Timer.hpp"
#include "StateBestScore.hpp"
#include "BestScore.hpp"
#include "Level.hpp"
#include "Point.hpp"

namespace Minesweeper
{
	struct GameData;
	class StateGame : public State
	{
	public:
		StateGame(const std::shared_ptr<GameData>& data, Level level);

		void Init() override;
		void HandleInput() override;
		void Update() override;
		void Draw() override;

	private:
		std::shared_ptr<GameData> _data;
		std::shared_ptr<Board> _board;
		Timer _timer;
		Level _level;
		int _bombs;
		int _timeScore;
		bool _game = true;
		sf::Sprite _background;
		sf::Sprite _tiles;
		sf::Sprite _headN;
		sf::Sprite _headW;
		sf::Sprite _headL;
		sf::Sprite _textBckgPoints;
		sf::Sprite _textBckgTime;
		std::ostringstream _bombsCounter;
		std::ostringstream _timeCounter;
		sf::Text _bombsCounterText;
		sf::Text _timeCounterText;
	};
}