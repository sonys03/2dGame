#ifndef PLAYER_H
#define PLAYER_H

#include <vector>
#include <iostream>
#include <fstream>
#include <limits>

using namespace std;

const int GRID_SIZE = 10;
const int MAX_SHIPS = 10;

class Player {
protected:
    vector<vector<int>> grid;
    int ships_left;

public:
    Player();
    virtual void placeShips() = 0;
    bool attack(int x, int y);
    int getShipsLeft() const;
    void displayConsoleGrid(bool revealShips = false) const;
    void saveGridToFile(const string& filename);
    void loadGridFromFile(const string& filename);

};

#endif // PLAYER_H
