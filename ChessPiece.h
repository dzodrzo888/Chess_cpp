#ifndef CHESSPIECE_H
#define CHESSPIECE_H
#include <utility>
#include <string> 

class ChessPiece {
private:
    int x;
    int y;
    std::string color;

public:
    // Constructor used to initialize the ChessPiece with its coordinates.
    ChessPiece(int x, int y) : x(x), y(y) {}

    // Sets pieces coordinates
    virtual void setPieceCoordinates(int x, int y);
    // Gets pieces coordinates
    std::pair<int, int> getCoordinates(int x, int y) {
        return {this->x, this->y};
    };
    // Checks if move is a valid move.
    virtual bool isValidMove(int x, int y) const = 0;

};

#endif 