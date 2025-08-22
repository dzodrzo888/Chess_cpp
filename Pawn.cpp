#include <iostream>
#include <string>
#include "Pawn.h"

bool Pawn::isValidMove(int x, int y) const {

    // Sets if the piece can move forward for white.
    bool x_axis_move_bool = this->x - x == allowedSquares;

    if (!this->hasMoved && !x_axis_move_bool) {
        x_axis_move_bool = this->x - x + 1 == allowedSquares;

        if (this->color == "black") {
            x_axis_move_bool = this->x - x - 1 == allowedSquares;
        }

    }

    if (this->y == y && x_axis_move_bool) {
        return true;
    }
    return false;
}

void Pawn::firstMove() {
    this->hasMoved = true;
    if (this->color == "black") {
        this->allowedSquares = -1;
    } else {
        this->allowedSquares = 1;
    }
}
