#include <iostream>
#include "Bishop.h"

bool Bishop::isValidMove(int x, int y) const {
    if (std::abs(x - this->x) == std::abs(y - this->y)) {
        return true;
    } else {
        return false;
    }
}