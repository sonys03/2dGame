#ifndef GAME_H
#define GAME_H

#include "human_player.h"
#include "computer_player.h"

class Game {
private:
    HumanPlayer human;
    ComputerPlayer computer;

public:
    Game();
    void start();
    void playTurn();
};

#endif // GAME_H
