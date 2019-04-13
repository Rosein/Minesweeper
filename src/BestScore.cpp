#include "../include/BestScore.hpp"

BestScore::BestScore(const int score, Level level) : _level(level)
{
    switch(_level)
        {
            case Level::EASY:
                _filepath = BEST_SCORE_EASY_LIST_FILEPATH;
                break;
            case Level::MEDIUM:
                _filepath = BEST_SCORE_MEDIUM_LIST_FILEPATH;
                break;
            case Level::HARD:
                _filepath = BEST_SCORE_HARD_LIST_FILEPATH;
                break;
        }
    
    std::ifstream readFile(_filepath);
    if (readFile.is_open() )
    {
        bool empty = (readFile.get(), readFile.eof() );
        if(!empty)
            while (!readFile.eof())
            {
                int i;
                readFile >> i;
                if(i!=0)
                    _bestScore.push_back(i);
            }
        readFile.close();
    }  
    if (_bestScore.size() < 5)
    {
        _bestScore.push_back(score);
        std::sort(begin(_bestScore), end(_bestScore));
        _changed = true;
    }
    else
    {
        for(int bScore : _bestScore)
            if(score < bScore)
            {
                _bestScore.push_back(score);
                std::sort(begin(_bestScore), end(_bestScore));
                _bestScore.pop_back();
                _changed = true;
                break;
            }
    }
    if(_changed)
    {
        std::ofstream writeFile(_filepath);
        if (writeFile.is_open())
        {
            for (int bScore : _bestScore)
                writeFile << '\n' << bScore;
            writeFile.close();
        }
    }
}

std::vector<int> BestScore::getBestScores()
{
    return _bestScore;
}