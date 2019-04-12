#pragma once

#include <SFML/Graphics.hpp>
#include <sstream>
#include <iostream>
#include "DEFINITIONS.hpp"
#include "State.hpp"
#include "Game.hpp"
#include "Timer.hpp"
#include "BestScore.hpp"

namespace Minesweeper
{
	struct GameData;
	class StateBestScore : public State
	{
	public:
		StateBestScore(const std::shared_ptr<GameData>& data, int timeScore);

		void Init() override;
		void HandleInput() override;
		void Update() override;
		void Draw() override;

	private:
		std::shared_ptr<GameData> _data;
		sf::Text _bestScoreText;
		std::ostringstream _bestScoreStream;
		int _timeScore;
		BestScore bScore;
	};
}