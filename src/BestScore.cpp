#include "../include/BestScore.hpp"

BestScore::BestScore()
{
    init(); 
}

BestScore::BestScore(const int score)
{
    init();   
    if (bestScore.size() < 5)
    {
        bestScore.push_back(score);
        std::sort(begin(bestScore), end(bestScore));
        changed = true;
    }
    else
    {
        for(int bScore : bestScore)
            if(score < bScore)
            {
                bestScore.push_back(score);
                std::sort(begin(bestScore), end(bestScore));
                bestScore.pop_back();
                changed = true;
                break;
            }
    }
    if(changed)
    {
        std::ofstream writeFile(BEST_SCORE_LIST_FILEPATH);
        if (writeFile.is_open())
        {
            for (int bScore : bestScore)
                writeFile << '\n' << bScore;
            writeFile.close();
        }
    }
}

void BestScore::init()
{
    std::ifstream readFile(BEST_SCORE_LIST_FILEPATH);
    if (readFile.is_open() )
    {
        bool empty = (readFile.get(), readFile.eof() );
        if(!empty)
            while (!readFile.eof())
            {
                int i;
                readFile >> i;
                if(i!=0)
                    bestScore.push_back(i);
            }
        readFile.close();
    }
}


std::vector<int> BestScore::getBestScores()
{
    return bestScore;
}