#include "game.h"
#include <iostream>

Game::Game() {}

void Game::start() {
    cout << "Welcome to Battleship!\n";
    human.placeShips();
    computer.placeShips();

    while (human.getShipsLeft() > 0 && computer.getShipsLeft() > 0) {
        playTurn();
    }

    cout << "Game over!\n";
    if (human.getShipsLeft() == 0)
        cout << "You lost! Better luck next time.\n";
    else
        cout << "Congratulations! You won!\n";

    // Вывод игровых полей
    cout << "\nYour grid:\n";
    human.displayConsoleGrid(true);

    cout << "\nComputer's grid (hidden ships):\n";
    computer.displayConsoleGrid(false);

    // Сохранение полей в файл
    human.saveGridToFile("human_final_grid.txt");
    computer.saveGridToFile("computer_final_grid.txt");

    cout << "Game grids saved to 'human_final_grid.txt' and 'computer_final_grid.txt'\n";
}

void Game::playTurn() {
    int user_x, user_y;
    int comp_x, comp_y;

    cout << "\nYour grid:\n";
    human.displayConsoleGrid(true);

    cout << "Enter coordinates to attack: ";
    cin >> user_x >> user_y;

    if (cin.fail() || user_x < 0 || user_x >= GRID_SIZE || user_y < 0 || user_y >= GRID_SIZE) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input. Try again.\n";
        return;
    }

    if (computer.attack(user_x, user_y))
        cout << "Hit!\n";
    else
        cout << "Miss.\n";

    cout << "Enemy ships remaining: " << computer.getShipsLeft() << "\n";

    // Компьютер атакует
    computer.attackRandomly(comp_x, comp_y);
    cout << "Computer attacks (" << comp_x << ", " << comp_y << ")\n";

    if (human.attack(comp_x, comp_y))
        cout << "Computer hit your ship!\n";
    else
        cout << "Computer missed.\n";

    cout << "Your ships remaining: " << human.getShipsLeft() << "\n";
}


