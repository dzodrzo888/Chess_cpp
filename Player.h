#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
#include <vector>

class Player {
private:
    std::string color;
    int playerNum;
    std::vector<char> piecesTaken;
    std::vector<char> piecesRemaining = {
        'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R', 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'
    };

public:
    void setColor(std::string color) {
        this->color = color;
    }

    void setPlayerNum(int playerNum) {
        this->playerNum = playerNum;
    }

    std::string getColor() {
        return this->color;
    }

    int getPlayerNum() {
        return this->playerNum;
    }

    std::vector<char> getPiecesTaken() {
        return this->piecesTaken;
    }

    std::vector<char> getPiecesRemaining() {
        return this->piecesRemaining;
    }

    void deletePiece(char piece);

    void pushPiece(char piece);

};

#endif