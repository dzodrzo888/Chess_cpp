#include <iostream>
#include "Board.h"
#include "Bishop.h"
#include "Queen.h"

int main() {
    Board board;

    Queen* queen = new Queen(2, 2, "White", "Q");

    Bishop* bishop = new Bishop(1, 1, "White", "B");

    board.setPiece(1, 1, bishop);

    board.setPiece(2, 2, queen);

    ChessPiece* bishop_piece = board.getPiece(1, 1);

    ChessPiece* queen_piece = board.getPiece(2, 2);

    board.displayBoard();

    board.movePiece(4, 4, bishop_piece);

    board.movePiece(4, 2, queen_piece);

    board.movePiece(2, 4, queen_piece);

    board.displayBoard();

    return 0;
}