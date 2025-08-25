// Obard.h used to define the board functionality
#ifndef BOARD_H
#define BOARD_H
#include <string>
#include "ChessPiece.h"

class Board {
private:
    // Board array definition. Might need changes.
    ChessPiece* board[8][8] = {nullptr};

public:

    // Destructor used to delete chess pieces from the heap.
    ~Board();

    // Sets a chess piece to a specific part of the board
    void setPiece(int x, int y, ChessPiece* piece);

    // Gets the piece
    ChessPiece* getPiece(int x, int y);

    // Moves the piece on the board.
    void movePiece(int x, int y, ChessPiece* piece);

    // Deletes the piece from the board.
    void deletePiece(int x, int y);

    // Displays the board.
    void displayBoard();

    // Populates the board with pieces
    void populateBoard(std::string color);

};

#endif