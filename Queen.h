#ifndef QUEEN_H
#define QUEEN_H
#include <iostream>
#include "ChessPiece.h"

class Queen : public ChessPiece {

public:
    Queen(int x, int y, std::string c, char n) : ChessPiece(x, y, c, n) {}

    bool isValidMove(int x, int y) const override;

};

#endif