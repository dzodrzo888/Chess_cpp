#include <iostream>
#include "King.h"

bool King::isValidMove(int x, int y) const {
    if (std::max(std::abs(x - this->x), std::abs(y - this->y)) <= 1) {
        return true;
    } else {
        return false;
    }
}