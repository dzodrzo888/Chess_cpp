#include <iostream>
#include "Board.h"
#include "Pawn.h"

int main() {
    Board board;
    
    Pawn* pawn = new Pawn(3, 3, "white", "P");

    board.setPiece(3, 3, pawn);

    ChessPiece* piece = board.getPiece(3, 3);

    board.displayBoard();

    board.movePiece(2, 3, piece);

    board.displayBoard();

    return 0;
}