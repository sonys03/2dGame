#include "player.h"

Player::Player() : ships_left(MAX_SHIPS), grid(GRID_SIZE, vector<int>(GRID_SIZE, 0)) {}

bool Player::attack(int x, int y) {
    if (grid[x][y] == 1) {
        grid[x][y] = 2;  // Попадание
        ships_left--;
        return true;
    }
    else if (grid[x][y] == 0) {
        grid[x][y] = -1; // Промах
        return false;
    }
    else {
        cout << "You have already attacked this position. Try again.\n";
        return false;
    }
}


int Player::getShipsLeft() const {
    return ships_left;
}

void Player::displayConsoleGrid(bool revealShips) const {
    cout << "  ";
    for (int i = 0; i < GRID_SIZE; ++i) cout << i << " ";
    cout << "\n";

    for (int i = 0; i < GRID_SIZE; ++i) {
        cout << i << " ";
        for (int j = 0; j < GRID_SIZE; ++j) {
            if (grid[i][j] == 2) cout << "X ";  // Попадание
            else if (grid[i][j] == -1) cout << "O ";  // Промах
            else if (grid[i][j] == 1 && revealShips) cout << "S ";  // Корабль
            else cout << "~ ";  // Пустая клетка
        }
        cout << "\n";
    }
}

void Player::saveGridToFile(const string& filename) {
    ofstream file(filename);
    if (!file.is_open()) {
        cerr << "Error: Unable to open file " << filename << "\n";
        return;
    }

    for (const auto& row : grid) {
        for (int cell : row) {
            file << cell << " ";
        }
        file << "\n";
    }

    file.close();
    cout << "Grid successfully saved to " << filename << "\n";
}


void Player::loadGridFromFile(const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Error: Unable to open file " << filename << "\n";
        return;
    }

    for (int i = 0; i < GRID_SIZE; ++i) {
        for (int j = 0; j < GRID_SIZE; ++j) {
            file >> grid[i][j];
            if (grid[i][j] != 0 && grid[i][j] != 1) {
                cerr << "Error: Invalid data in file " << filename << "\n";
                file.close();
                return;
            }
        }
    }

    file.close();
    cout << "Grid successfully loaded from " << filename << "\n";
}


