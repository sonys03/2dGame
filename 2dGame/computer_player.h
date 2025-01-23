#ifndef COMPUTER_PLAYER_H
#define COMPUTER_PLAYER_H

#include "player.h"
#include <cstdlib>
#include <set>

class ComputerPlayer : public Player {
public:
    void placeShips() override;
    bool attackRandomly(int& x, int& y);
private:
    bool checkValidPlacement(int x, int y);
    set<pair<int, int>> attackedPositions;  // Для хранения координат атак
};

#endif // COMPUTER_PLAYER_H
