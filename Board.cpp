#include "Board.h"
#include "ChessPiece.h"
#include "Tower.h"
#include "Knight.h"
#include "Bishop.h"
#include "Queen.h"
#include "King.h"
#include "Pawn.h"
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
        
    std::pair<int, int> coords = piece->getCoordinates();

    deletePiece(coords.first, coords.second);

    piece->setPieceCoordinates(x, y);

    this->board[x][y] = piece;

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

void Board::populateBoard(std::string color) {
    // This function fucking sucks maybe try using a switch statements plus dict like struct
    int non_pawn_piece_block = 0;
    int pawn_piece_block = 1;

    if (color == "white") {
        non_pawn_piece_block = 7;
        pawn_piece_block = 6;
    }

    for (int j = 0; j < 8; j++) {
        if ((j == 0 || j == 7)) {
            Tower* tower = new Tower(non_pawn_piece_block, j, color, "T");
            setPiece(non_pawn_piece_block, j, tower);
        } else if ((j == 1 || j == 6)) {
            Knight* knight = new Knight(non_pawn_piece_block, j, color, "N");
            setPiece(non_pawn_piece_block, j, knight);
        } else if ((j == 2 || j == 5)) {
            Bishop* bishop = new Bishop(non_pawn_piece_block, j, color, "B");
            setPiece(non_pawn_piece_block, j, bishop);
        } else if (j == 3) {
            Queen* queen = new Queen(non_pawn_piece_block, j, color, "Q");
            setPiece(non_pawn_piece_block, j , queen);
        } else if (j == 4) {
            King* king = new King(non_pawn_piece_block ,j, color, "K");
            setPiece(non_pawn_piece_block, j ,king);
        }
    }

    for (int j = 0; j < 8; j++) {
        Pawn* pawn = new Pawn(pawn_piece_block, j, color, "P");
        setPiece(pawn_piece_block, j, pawn);
    }
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