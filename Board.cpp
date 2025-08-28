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

    delete piece;
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

    setPiece(x, y, piece);

}

ChessPiece* Board::getPiece(int x, int y) {

    return this->board[x][y];
}

void Board::setPiece(int x, int y, ChessPiece* piece) {
    this->board[x][y] = piece;
}

void Board::populateBoard(std::string color) {
    
    int back_rank = (color == "white") ? 7 : 0;
    int pawn_rank = (color == "white") ? 6 : 1;

    for (int j = 0; j < 8; j++) {
        ChessPiece* piece = nullptr;
        switch(j) {
            case 0:
            case 7:
                piece = new Tower(back_rank, j, color, 'R');
                break;
            case 1:
            case 6:
                piece = new Knight(back_rank, j, color, 'N');
                break;
            case 2:
            case 5:
                piece = new Bishop(back_rank, j, color, 'B');
                break;
            case 3:
                piece = new Queen(back_rank, j, color, 'Q');
                break;
            case 4:
                piece = new King(back_rank ,j, color, 'K');
                break;
        }
        setPiece(back_rank, j, piece);
    }

    for (int j = 0; j < 8; j++) {
        Pawn* pawn = new Pawn(pawn_rank, j, color, 'P');
        setPiece(pawn_rank, j, pawn);
    }

}

bool Board::isMoveDiagonal(int xStart, int yStart, int xEnd, int yEnd) {
    if (std::abs(xEnd - xStart) == std::abs(yEnd - yStart)) {
        return true;
    } else {
        return false;
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

    bool moveDiagonal = isMoveDiagonal(xStart, yStart, xEnd, yEnd);

    bool pathClear = (moveDiagonal) ? isPieceInWayDiagonal(xStart, yStart, xEnd, yEnd, piece) : 
                                      isPieceInWayStraight(xStart, yStart, xEnd, yEnd, piece);

    return pathClear;
}

Board::~Board() {
    for (int i = 0; i < 8; i++) {
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