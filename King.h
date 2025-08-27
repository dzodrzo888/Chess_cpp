#ifndef KING_H
#define KING_H
#include "ChessPiece.h"
#include <string>

class King : public ChessPiece {

public:
    King(int x, int y, std::string c, char n) : ChessPiece(x, y, c, n) {}

    bool isValidMove(int x, int y) const override;

};

#endif