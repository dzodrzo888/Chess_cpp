#include <iostream>
#include <algorithm>
#include <typeinfo>
#include "Player.h"

void Player::removeActivePiece(char piece) {
    auto itr = std::find(this->piecesRemaining.begin(), this->piecesRemaining.end(), piece);
    if (itr != this->piecesRemaining.end()) this->piecesRemaining.erase(itr);
}

void Player::addCapturedPiece(char piece) {

    this->piecesTaken.push_back(piece);

}