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
                std::cout << board[i][j];
            }
        }
        std::cout << std::endl;
    }
}

Board::~Board() {
    for (int i =0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {

            // Only delete if board[i][j] is a ChessPiece pointer, not "."
            if (board[i][j] != nullptr) {

            delete board[i][j];
            }
        }
    }
    std::cout << "Board destructed!" << "\n";
}