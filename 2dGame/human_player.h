#ifndef HUMAN_PLAYER_H
#define HUMAN_PLAYER_H

#include "player.h"

class HumanPlayer : public Player {
public:
    void placeShips() override;
};

#endif // HUMAN_PLAYER_H
