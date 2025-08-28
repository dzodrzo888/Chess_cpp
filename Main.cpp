#include <iostream>
#include "Game.h"

int main() {
    Game game(true, false);
    std::cout << "Game initialized" << "\n";
    game.initializeGame();

    game.startGame();

    return 0;
}