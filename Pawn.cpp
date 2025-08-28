#include <iostream>
#include <string>
#include "Pawn.h"

bool Pawn::isValidMove(int x, int y) const {
    if (x < 0 || x >= 8 || y < 0 || y >= 8) return false;
    int dx = x - this->x;
    int dy = y - this->y;

    if (dy == 0) {
        if (color == "black") return (dx == 1 || (!hasMoved && dx == 2));
        else return (dx == -1 || (!hasMoved && dx == -2));
    }

    if (abs(dy) == 1) {
        if (color == "black") return (dx == 1);
        else return (dx == -1);
    }

    return false;
}

void Pawn::firstMove() {
    this->hasMoved = true;
}
