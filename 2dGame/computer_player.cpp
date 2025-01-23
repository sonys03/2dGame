#include "computer_player.h"

// ѕроверка на допустимое размещение корабл€ (нет соседних кораблей)
bool ComputerPlayer::checkValidPlacement(int x, int y) {
    for (int dx = -1; dx <= 1; ++dx) {
        for (int dy = -1; dy <= 1; ++dy) {
            int nx = x + dx, ny = y + dy;
            if (nx >= 0 && nx < GRID_SIZE && ny >= 0 && ny < GRID_SIZE) {
                if (grid[nx][ny] == 1) return false;  // —оседний корабль найден
            }
        }
    }
    return true;
}

// —лучайное размещение кораблей с проверкой на корректность
void ComputerPlayer::placeShips() {
    int placed = 0;
    while (placed < MAX_SHIPS) {
        int x = rand() % GRID_SIZE;
        int y = rand() % GRID_SIZE;
        if (grid[x][y] == 0 && checkValidPlacement(x, y)) {
            grid[x][y] = 1;
            placed++;
        }
    }
}

bool ComputerPlayer::attackRandomly(int& attack_x, int& attack_y) {
    int x, y;
    do {
        x = rand() % GRID_SIZE;
        y = rand() % GRID_SIZE;
    } while (attackedPositions.count({ x, y }) > 0);

    attackedPositions.insert({ x, y });
    attack_x = x;
    attack_y = y;
    return attack(x, y);
}


