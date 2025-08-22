#ifndef BISHOP_H
#define BISHOP_H
#include <iostream>
#include "ChessPiece.h"

class Bishop : public ChessPiece {

public:
    Bishop(int x, int y, std::string c, std::string n) : ChessPiece(x, y, c, n) {}

    bool isValidMove(int x, int y) const override;

};

#endif