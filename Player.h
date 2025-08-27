#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
#include <vector>

class Player {
private:
    std::string color;
    std::vector<char> piecesTaken;
    std::vector<char> piecesRemaining = {
        'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R', 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'
    };

public:
    Player(std::string c) : color(c) {};

    std::string getColor() {
        return this->color;
    }

    std::vector<char> getPiecesTaken() {
        return this->piecesTaken;
    }

    std::vector<char> getPiecesRemaining() {
        return this->piecesRemaining;
    }

    void removeActivePiece(char piece);

    void addCapturedPiece(char piece);

};

#endif