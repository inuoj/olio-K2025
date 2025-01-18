#ifndef GAME_H
#define GAME_H
#include <iostream>
using namespace std;

class game
{
public:
    game();
    ~game();
    void play();
private:
    int maxNumber;
    int playerGuess = 0;
    int randomNumber;
    int numOfGuesses = 0;
    void printGameResult(int);
};

#endif // GAME_H
