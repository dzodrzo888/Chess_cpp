#include <iostream>
#include "Queen.h"

bool Queen::isValidMove(int x, int y) const {
    if ((std::abs(x - this->x) == std::abs(y - this->y)) || 
        ((this->x == x && this->y != y) || (this->x != x && this->y == y))
    ) {
        return true;
    } else {
        return false;
    }
}