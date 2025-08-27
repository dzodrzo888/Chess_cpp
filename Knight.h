#ifndef KNIGHT_H
#define KNIGHT_H
#include <iostream>
#include "ChessPiece.h"

class Knight : public ChessPiece {

public:
    Knight(int x, int y, std::string c, char n) : ChessPiece(x, y, c, n) {}

    bool isValidMove(int x, int y) const override;

};

#endif