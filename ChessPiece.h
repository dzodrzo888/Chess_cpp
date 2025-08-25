#ifndef CHESSPIECE_H
#define CHESSPIECE_H
#include <utility>
#include <string> 

class ChessPiece {
protected:
    int x;
    int y;
    std::string color;
    std::string name;
    bool hasMoved = false;

public:
    // Constructor used to initialize the ChessPiece with its coordinates.
    ChessPiece(int x, int y, std::string c, std::string n) : x(x), y(y), color(c), name(n) {}

    // Sets pieces coordinates
    void setPieceCoordinates(int x, int y) {
        this->x = x;
        this->y = y;
    };

    // Gets pieces coordinates
    std::pair<int, int> getCoordinates() {
        return {this->x, this->y};
    };

    std::string getName() {
        return this->name;
    }

    std::string getColor() {
        return this->color;
    }

    // Checks if move is a valid move.
    virtual bool isValidMove(int x, int y) const = 0;

    // Desctructor
    virtual ~ChessPiece() {}
};

#endif 