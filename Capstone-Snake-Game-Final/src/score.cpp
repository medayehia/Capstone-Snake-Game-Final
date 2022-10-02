#include "score.h"

Score::Score()
{

}

void Score::writeScore(int score)
{
   _boardFile.open("ScoreBoard.txt", fstream::app);
   _boardFile << "Player_Score: " << score << "\n";
   _boardFile.close();
}

int Score::topScore()
{
    _scoreBoard.open("ScoreBoard.txt");
    if(_scoreBoard.is_open())
    {
        while(std::getline(_scoreBoard, line))
        {
            std::istringstream linestream(line);
            linestream >> key >> value;
            if(key == "Player_Score:")
            {
                if(stoi(value) >= highScore)
                {
                    highScore = stoi(value);
                }
            }
        }
    }
    _scoreBoard.close();
    return highScore;
}

