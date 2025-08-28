// Obard.h used to define the board functionality
#ifndef BOARD_H
#define BOARD_H
#include <string>
#include <map>
#include <utility>
#include "ChessPiece.h"
#include "Player.h"

class ChessPiece;

class Board {
private:
    // Board array definition. Might need changes.
    ChessPiece* board[8][8] = {nullptr};
    std::map <std::string, std::pair<int, int>> chessPiecesCords;
    std::string isInCheck = "";

public:

    // Destructor used to delete chess pieces from the heap.
    ~Board();

    // Sets a chess piece to a specific part of the board
    void setPiece(int x, int y, ChessPiece* piece);

    // Gets the piece
    ChessPiece* getPiece(int x, int y);

    // Moves the piece on the board.
    void movePiece(int x, int y, ChessPiece* piece, Player* player1, Player* player2);

    // Displays the board.
    void displayBoard();

    // Populates the board with pieces
    void populateBoard(std::string color);

    bool isPieceInWayStraight(int xStart, int yStart, int xEnd, int yEnd, ChessPiece* piece);

    bool isPieceInWayDiagonal(int xStart, int yStart, int xEnd, int yEnd, ChessPiece* piece);

    bool isPathClear(int xStart, int yStart, int xEnd, int yEnd, ChessPiece* piece);

    void takePiece(int x, int y, Player* player1, Player* player2);

    bool isMoveDiagonal(int xStart, int yStart, int xEnd, int yEnd); 

    void mapChessPiece(int x, int y, std::string piece);

    std::pair<int, int> getPieceCords(std::string piece);

    bool checkIfInCheck(std::string color);

    void setInCheck(std::string color);

    std::string getInCheck();
};

#endif