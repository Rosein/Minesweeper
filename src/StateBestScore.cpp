#include "../include/StateBestScore.hpp"


namespace Minesweeper
{
	StateBestScore::StateBestScore(const std::shared_ptr<GameData>& data, int timeScore) : _data(data), _timeScore(timeScore)
	{

	}

	void StateBestScore::Init()
	{
		_bestScoreStream << "Your score is: " << std::endl;
		_bestScoreStream << std::setfill(' ') << std::setw(8) << " " << std::setfill('0') << std::setw(3) << _timeScore << std::endl;
		_bestScoreStream << "\nBest scores: " << std::endl;
		auto bScores = bScore.getBestScores();
		for ( int elem : bScores)
        	_bestScoreStream << std::setfill(' ') << std::setw(8) << " "  << std::setfill('0') << std::setw(3) << elem << " \n";

		_bestScoreText.setFont(_data->assets.LoadAndGetFont(BEST_SCORE_FONT_FILEPATH));
		_bestScoreText.setCharacterSize(30);
		_bestScoreText.setFillColor(sf::Color::Black);
		_bestScoreText.setString(_bestScoreStream.str());
		_bestScoreText.setOrigin(_bestScoreText.getGlobalBounds().width / 2, _bestScoreText.getGlobalBounds().height / 2);
		_bestScoreText.setPosition(_data -> window.getSize().x / 2, _data -> window.getSize().y / 2);
	}

	void StateBestScore::HandleInput()
	{
		sf::Event event;

		while (_data->window.pollEvent(event))
		{
			if (sf::Event::Closed == event.type)
			{
				_data->window.close();
			}
		}
	}

	void StateBestScore::Update()
	{
		
	}

	void StateBestScore::Draw()
	{
		_data->window.clear(sf::Color(192, 192, 192, 255));
		_data->window.draw(_bestScoreText);
		_data->window.display();
	}
}