#include <iostream>
#include "Tower.h"

bool Tower::isValidMove(int x, int y) const {
    if ((this->x == x && this->y != y) || (this->x != x && this->y == y)) {
        return true;
    } else {
        return false;
    }
}
