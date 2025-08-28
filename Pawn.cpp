#include <iostream>
#include <string>
#include "Pawn.h"

bool Pawn::isValidMove(int x, int y) const {
    if (x < 0 || x >= 8 || y < 0 || y >= 8) return false;
    int dx = x - this->x;
    int dy = y - this->y;

    if (dy != 0) return false;

    if (this->color == "black") {

    if (!hasMoved && dx == 2) return true;
    if (dx == 1) return true;
    } else {
    
        if (!hasMoved && dx == -2) return true;
        if (dx == -1) return true;
    }

    return false;
}

void Pawn::firstMove() {
    this->hasMoved = true;
}
