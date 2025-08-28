#include <iostream>
#include "Game.h"

void Game::initializeGame() {

    player1 = new Player("white");

    player2 = new Player("black");

    board.populateBoard("black");

    board.populateBoard("white");

}

void Game::startGame() {
    while (true) {
        board.displayBoard();

        processMove();
    }
}

void Game::changeTurn() {
    this->isWhiteTurn = !this->isWhiteTurn;
}

void Game::displayGameState() {

    board.displayBoard();

    std::cout << "\n";

    std::cout << "Player 1 remaining pieces: ";
    for (char piece : player1->getPiecesRemaining()) {
        std::cout << piece << " ";
    }
    std::cout << "\n";
    
    std::cout << "Player 1 captured pieces: ";
    for (char piece : player1->getPiecesTaken()) {
        std::cout << piece << " ";
    }
    std::cout << "\n";
    
    std::cout << "Player 2 remaining pieces: ";
    for (char piece : player2->getPiecesRemaining()) {
        std::cout << piece << " ";
    }
    std::cout << "\n";
    
    std::cout << "Player 2 captured pieces: ";
    for (char piece : player2->getPiecesTaken()) {
        std::cout << piece << " ";
    }
    std::cout << "\n";

}

void Game::processMove() {
    while (true) {
        std::string move;

        if (this->isWhiteTurn) {
        std::cout << "Whites turn!" << "\n";
        } else {
            std::cout << "Blacks turn!" << "\n";
        }

        std::cout << "Please make a move: ";

        std::cin >> move;

        std::cout << "\n";

        int x1 = move[0] - '0';
        int y1 = move[1] - '0';

        int x2 = move[2] - '0';
        int y2 = move[3] - '0';
        
        ChessPiece* piece = board.getPiece(x1, y1);

        bool moveValid = validateMove(x1, y1, x2, y2, piece);

        if (moveValid) {
            
            board.movePiece(x2, y2, piece, player1, player2);
            
            displayGameState();

            changeTurn();
            
            break;
        }
    }
}

bool Game::validateMove(int x1, int y1, int x2, int y2, ChessPiece* piece) {
    std::string curr_color = (this->isWhiteTurn) ? "white" : "black";
    
    if (piece == nullptr) {
        std::cout << "No Piece in this location please choose a valid peace!" << "\n";
        return false;
    }

    if (piece->getColor() !=  curr_color) {
        std::cout << "Please choose a piece of your own color!" << "\n";
        return false;
    }

    bool isValid = piece->isValidMove(x2, y2);

    bool moveDiagonal = board.isMoveDiagonal(x1, y1, x2, y2);

    if (isValid && piece->getName() == 'P' && board.getPiece(x2, y2) == nullptr && moveDiagonal) {
        isValid = false;
    }

    if (!isValid) {
        std::cout <<"Move not valid!" << "\n";
        return false;
    } 

    bool path_clear = board.isPathClear(x1, y1, x2, y2, piece);

    if (!path_clear) {
        std::cout << "Path not clear!" << "\n";
        return false;
    } 

    return true;
}

void Game::isGameOver() {
    std::cout << "Winner of this game is: " << this->winner << "\n";

    delete player1;
    delete player2;
}