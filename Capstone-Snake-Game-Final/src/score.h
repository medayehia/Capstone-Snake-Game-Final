#ifndef SCORE_H
#define SCORE_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>

using namespace  std;

class Score
{
public:
    Score();
    void writeScore(int score);
    int topScore();

private:
    ofstream _boardFile;
    ifstream _scoreBoard;
    string line;
    string key;
    string value{'0'};
    int highScore{0};
};

#endif
