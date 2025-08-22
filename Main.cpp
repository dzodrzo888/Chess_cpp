#include <iostream>
#include "Board.h"
#include "Pawn.h"
#include "Tower.h"

int main() {
    Board board;
    
    Pawn* pawn = new Pawn(3, 3, "white", "P");

    Tower* tower = new Tower(0, 0, "white", "T");

    board.setPiece(3, 3, pawn);

    board.setPiece(0, 0, tower);

    ChessPiece* pawn_piece = board.getPiece(3, 3);

    ChessPiece* tower_piece = board.getPiece(0, 0);

    board.displayBoard();

    board.movePiece(2, 3, pawn_piece);

    board.movePiece(7, 0, tower_piece);

    board.displayBoard();

    return 0;
}