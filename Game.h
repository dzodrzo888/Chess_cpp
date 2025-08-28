#ifndef GAME_H
#define GAME_H
#include "Board.h"
#include "Player.h"
#include "ChessPiece.h"

class Game {
private:
    Board board;
    Player* player1;
    Player* player2;
    bool isWhiteTurn;
    bool gameOver;
    std::string winner;

public:
    Game(bool iWT, bool gO) : isWhiteTurn(iWT), gameOver(gO) {}
    
    void initializeGame();

    void startGame();

    void changeTurn();

    void processMove();

    bool validateMove(int x1, int y1, int x2, int y2, ChessPiece* piece);

    // Display board, whos turn and who has what pieces
    void displayGameState();

    void isGameOver();

};

#endif