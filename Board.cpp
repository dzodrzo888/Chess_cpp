#include "Board.h"
#include "ChessPiece.h"
#include "Tower.h"
#include "Knight.h"
#include "Bishop.h"
#include "Queen.h"
#include "King.h"
#include "Pawn.h"
#include "Player.h"
#include <iostream>
#include <string>

void Board::displayBoard() {

    std::cout << "\n";

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

    std::cout << "\n";
}

void Board::takePiece(int x, int y, Player* player1, Player* player2) {
    
    ChessPiece* piece = board[x][y];
    if (!piece) return;

    Player* playerToGivePiece = (player1->getColor() == piece->getColor()) ? player1 : player2;

    Player* playerToTakePiece = (player1->getColor() != piece->getColor()) ? player1 : player2;

    playerToGivePiece->removeActivePiece(piece->getName());

    playerToTakePiece->addCapturedPiece(piece->getName());

    this->board[x][y] = nullptr;
    
    std::cout << "Piece deleted succesfully" << "\n";

}

void Board::movePiece(int x, int y, ChessPiece* piece, Player* player1, Player* player2) {
    
    std::pair<int, int> coords = piece->getCoordinates();

    if (board[x][y] != nullptr) {

        takePiece(x, y, player1, player2);
    
    }

    this->board[coords.first][coords.second] = nullptr;

    piece->setPieceCoordinates(x, y);

    this->board[x][y] = piece;

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
            Tower* tower = new Tower(non_pawn_piece_block, j, color, 'R');
            setPiece(non_pawn_piece_block, j, tower);
        } else if ((j == 1 || j == 6)) {
            Knight* knight = new Knight(non_pawn_piece_block, j, color, 'N');
            setPiece(non_pawn_piece_block, j, knight);
        } else if ((j == 2 || j == 5)) {
            Bishop* bishop = new Bishop(non_pawn_piece_block, j, color, 'B');
            setPiece(non_pawn_piece_block, j, bishop);
        } else if (j == 3) {
            Queen* queen = new Queen(non_pawn_piece_block, j, color, 'Q');
            setPiece(non_pawn_piece_block, j , queen);
        } else if (j == 4) {
            King* king = new King(non_pawn_piece_block ,j, color, 'K');
            setPiece(non_pawn_piece_block, j ,king);
        }
    }

    for (int j = 0; j < 8; j++) {
        Pawn* pawn = new Pawn(pawn_piece_block, j, color, 'P');
        setPiece(pawn_piece_block, j, pawn);
    }
}

bool Board::isPieceInWayStraight(int xStart, int yStart, int xEnd, int yEnd, ChessPiece* piece) {
    int dx = (xEnd > xStart) ? 1 : (xEnd < xStart ? -1 : 0);
    int dy = (yEnd > yStart) ? 1 : (yEnd < yStart ? -1 : 0);

    int cx = xStart;
    int cy = yStart;

    while(cx != xEnd || cy != yEnd) {

        cx += dx;
        cy += dy;

        ChessPiece* curr_square_piece = getPiece(cx, cy);

        if (curr_square_piece != nullptr) {

            if (cx == xEnd && cy == yEnd && curr_square_piece->getColor() != piece->getColor()) continue;

            std::cout << "Piece is in the way!" << "\n";

            return false;
        }

    }
    return true;
}

bool Board::isPieceInWayDiagonal(int xStart, int yStart, int xEnd, int yEnd, ChessPiece* piece) {
    int dx = (xEnd > xStart) ? 1 : -1;
    int dy = (yEnd > yStart) ? 1 : -1;

    int cx = xStart;
    int cy = yStart;

    while(cx != xEnd && cy != yEnd) {

        cx += dx;
        cy += dy;

        ChessPiece* curr_square_piece = getPiece(cx, cy);

        if (curr_square_piece != nullptr) {

            if (cx == xEnd && cy == yEnd && curr_square_piece->getColor() != piece->getColor()) continue;

            std::cout << "Piece is in the way!" << "\n";

            return false;
        }
    }
    return true;
}

bool Board::isPathClear(int xStart, int yStart, int xEnd, int yEnd, ChessPiece* piece) {
    bool pieceInWayStraight;
    bool pieceInWayDiagonal;
    bool result;

    if (piece->getName() == 'R' || piece->getName() == 'P') {
        pieceInWayStraight = isPieceInWayStraight(xStart, yStart, xEnd, yEnd, piece);
        return pieceInWayStraight;
    } else if (piece->getName() == 'B') {
        pieceInWayDiagonal = isPieceInWayDiagonal(xStart, yStart, xEnd, yEnd, piece);
        return pieceInWayDiagonal;
    } else if (piece->getName() == 'Q') {
        pieceInWayStraight = isPieceInWayStraight(xStart, yStart, xEnd, yEnd, piece);
        pieceInWayDiagonal = isPieceInWayDiagonal(xStart, yStart, xEnd, yEnd, piece);

        result = pieceInWayStraight || pieceInWayDiagonal;

        return result;
    }

    return true;
}

Board::~Board() {
    for (int i =0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {

            // Only delete if board[i][j] is a ChessPiece pointer, not "."
            if (this->board[i][j] != nullptr) {
            delete this->board[i][j];
            board[i][j] = nullptr;
            }
        }
    }
    std::cout << "Board destructed!" << "\n";
}