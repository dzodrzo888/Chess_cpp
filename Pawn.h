#ifndef PAWN_H
#define PAWN_H
#include "ChessPiece.h"
#include <string>

class Pawn : public ChessPiece {
private:
    int allowedSquares = 2;

public:
    Pawn(int x, int y, std::string c, std::string n) : ChessPiece(x, y, c, n) {
        if (n == "black") {
            allowedSquares = -2;
        }
    }

    bool isValidMove (int x, int y) const override;

    void firstMove();

};

#endif