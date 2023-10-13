#pragma once
#include <iostream>
using namespace std;
class Piece
{
private:
    static const int INDEX_LEFT = 0;
    static const int INDEX_TOP = 1;
    static const int INDEX_RIGHT = 2;
    static const int INDEX_BOTTOM = 3;

    int _values[4] = { -1, -1, -1, -1 };
public:
    Piece();
    Piece(int leftValue, int topValue, int rightValue, int bottomValue);

    int getLeft() const;
    int getTop() const;
    int getRight() const;
    int getBottom() const;

    bool canBePlacedAtLeftOf(Piece *piece);
    bool canBePlacedAtTopOf(Piece *piece);
    bool canBePlacedAtRightOf(Piece *piece);
    bool canBePlacedAtBottomOf(Piece *piece);

    bool isEmpty();

    friend bool operator== (const Piece &leftPiece, const Piece &rightPiece);
    friend ostream& operator<< (ostream& os, const Piece& piece);

};
    

