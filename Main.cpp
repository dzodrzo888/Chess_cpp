#include <iostream>
#include <string>
#include "Board.h"

int main() {
    Board board;
    std::string move;
    bool playerturn = true;
    std::string curr_color;
    int x1;
    int x2;
    int y1;
    int y2;
    ChessPiece* piece;
    bool isValid;

    board.populateBoard("black");

    board.populateBoard("white");

    board.displayBoard();

    while (true) {
    
        if (playerturn) {
            std::cout << "Whites turn!" << "\n";
            curr_color = "white";
        } else {
            std::cout << "Blacks turn" << "\n";
            curr_color = "black";
        }

        while (true) {
            std::cout << "Please make a move: ";

            std::cin >> move;

            x1 = move[0] - '0';
            y1 = move[1] - '0';

            x2 = move[2] - '0';
            y2 = move[3] - '0';

            piece = board.getPiece(x1, y1);

            if (piece == nullptr) {
                std::cout << "No Piece in this location please choose a valid peace!" << "\n";
                continue;
            }

            if (piece->getColor() !=  curr_color) {
                std::cout << "Please choose a piece of your own color!" << "\n";
                continue;
            }

            isValid = piece->isValidMove(x2, y2);

            if (isValid) {
                std::cout << "Move sucessful!" << "\n";
                break;
            } else {
                std::cout <<"Move not valid!" << "\n";
            }

        }

        board.movePiece(x2, y2, piece);

        board.displayBoard();

        playerturn = !playerturn;

    }

    return 0;
}