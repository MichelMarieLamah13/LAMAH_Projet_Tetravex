#include "../headers/Piece.h"

Piece::Piece()
{
}

Piece::Piece(int leftValue, int topValue, int rightValue, int bottomValue)
{
    _values[INDEX_LEFT] = leftValue;
    _values[INDEX_TOP] = topValue;
    _values[INDEX_RIGHT] = rightValue;
    _values[INDEX_BOTTOM] = bottomValue;
}

int Piece::getLeft() const
{
    return _values[INDEX_LEFT];
}

int Piece::getTop() const
{
    return _values[INDEX_TOP];
}

int Piece::getRight() const
{
    return  _values[INDEX_RIGHT];
}

int Piece::getBottom() const
{
    return _values[INDEX_BOTTOM];
}

bool Piece::canBePlacedAtLeftOf(Piece *piece)
{
    return _values[INDEX_RIGHT] == -1 || _values[INDEX_RIGHT] == piece->getLeft();
}

bool Piece::canBePlacedAtTopOf(Piece *piece)
{
    return _values[INDEX_BOTTOM] == -1 || _values[INDEX_BOTTOM] == piece->getTop();
}

bool Piece::canBePlacedAtRightOf(Piece *piece)
{
    return _values[INDEX_LEFT] == -1 || _values[INDEX_LEFT] == piece->getRight();
}

bool Piece::canBePlacedAtBottomOf(Piece *piece)
{
    return _values[INDEX_TOP] == -1 || _values[INDEX_TOP] == piece->getBottom();
}

bool Piece::isEmpty()
{
    Piece piece;
    return *this == piece;
}

bool operator== (const Piece &leftPiece, const Piece &rightPiece)
{
    bool isEgal = true;
    for (int i = 0; i < 4 && isEgal; i++)
    {
        isEgal = leftPiece._values[i] == rightPiece._values[i];
    }
    return isEgal;
}

ostream& operator<< (ostream& os, const Piece& piece)
{
    os << "╔═══╗"<<endl;
    os << "║ "<<piece.getTop()<<" ║"<<endl;
    os << "║"<<piece.getLeft()<<" "<<piece.getRight()<<"║"<<endl;
    os << "║ "<<piece.getBottom()<<" ║"<<endl;
    os << "╚═══╝"<<endl;
    
    return os;
}