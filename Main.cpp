#include <iostream>
#include "Game.h"

int main() {
    Game game(true, false);

    game.initializeGame();

    game.startGame();

    return 0;
}