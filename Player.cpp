#include <iostream>
#include <algorithm>
#include "Player.h"

void Player::deletePiece(char piece) {
    auto itr = std::find(this->piecesRemaining.begin(), this->piecesRemaining.end(), piece);
    if (itr != this->piecesRemaining.end()) this->piecesRemaining.erase(itr);
}

void Player::pushPiece(char piece) {
    this->piecesTaken.push_back(piece);
}