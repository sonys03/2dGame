#include "human_player.h"

void HumanPlayer::placeShips() {
    char choice;
    cout << "Do you want to place ships manually (m), randomly (r), or load from file (f)? ";
    cin >> choice;

    if (choice == 'f') {
        string filename;
        cout << "Enter the filename: ";
        cin >> filename;
        loadGridFromFile(filename);
        return;
    }

    if (choice == 'r') {
        int placed = 0;
        while (placed < MAX_SHIPS) {
            int x = rand() % GRID_SIZE;
            int y = rand() % GRID_SIZE;
            if (grid[x][y] == 0) {
                grid[x][y] = 1;
                placed++;
            }
        }
        cout << "Ships placed randomly!\n";
    }
    else {
        int x, y;
        cout << "Place your ships (format: x y):\n";
        for (int i = 0; i < MAX_SHIPS; ++i) {
            while (true) {
                cout << "Ship " << i + 1 << ": ";
                cin >> x >> y;

                if (cin.fail() || x < 0 || x >= GRID_SIZE || y < 0 || y >= GRID_SIZE || grid[x][y] == 1) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Invalid position. Try again.\n";
                }
                else {
                    grid[x][y] = 1;
                    break;
                }
            }
        }
    }
}

