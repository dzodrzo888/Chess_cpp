#include "Board.h"
#include "ChessPiece.h"
#include <iostream>
#include <string>

void Board::displayBoard() {

    // Display each part of the board.
    for (int i = 0; i < 8; i++) {

        for (int j = 0; j < 8; j++) {
            // If no chesspiece display a single dot
            if (board[i][j] == nullptr) {
                std::cout << '.';
            }
            else {
                std::cout << board[i][j]->getName();
            }
        }
        std::cout << std::endl;
    }
}

void Board::movePiece(int x, int y, ChessPiece* piece) {
    bool isValidMove;

    isValidMove = piece->isValidMove(x, y);

    if (isValidMove) {
        std::pair<int, int> coords = piece->getCoordinates();

        deletePiece(coords.first, coords.second);

        piece->setPieceCoordinates(x, y);

        this->board[x][y] = piece;

    } else {
        std::cout << "Invalid move! Please choose a valid move!" << "\n";
    }
}

void Board::deletePiece(int x, int y) {
    this->board[x][y] = nullptr;
}

ChessPiece* Board::getPiece(int x, int y) {
    return this->board[x][y];
}

void Board::setPiece(int x, int y, ChessPiece* piece) {
    this->board[x][y] = piece;
}

Board::~Board() {
    for (int i =0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {

            // Only delete if board[i][j] is a ChessPiece pointer, not "."
            if (this->board[i][j] != nullptr) {

            delete this->board[i][j];
            }
        }
    }
    std::cout << "Board destructed!" << "\n";
}