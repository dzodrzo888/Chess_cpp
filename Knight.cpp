#include <iostream>
#include "Knight.h"

bool Knight::isValidMove(int x, int y) const {
    if ((std::abs(x - this->x) == 2 && std::abs(y - this->y) == 1) ||
        (std::abs(x - this->x) == 1 && std::abs(y - this->y) == 2)) {
            return true;
    } else {
        return false;;
    }
}