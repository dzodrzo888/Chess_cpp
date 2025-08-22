#ifndef TOWER_H
#define TOWER_H
#include <iostream>
#include "ChessPiece.h"

class Tower : public ChessPiece {

public:
    Tower(int x, int y, std::string c, std::string n) : ChessPiece(x, y, c, n) {}

    bool isValidMove(int x, int y) const override;

};

#endif