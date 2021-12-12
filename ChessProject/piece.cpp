#include "piece.h"

bool Piece::getColor() const
{
    return this->color;
}

Piece::Piece(const int x, const int y, const int color)
{
    this->setPose(x, y);
    this->color = color;
}

Piece::~Piece()
{
    //nothing to free cause no memory malloced
}

char Piece::getSymbol() const
{
    return this->symbol;
}

int Piece::getX() const
{
    return this->xAxis;
}

int Piece::getY() const
{
    return this->yAxis;
}

void Piece::setPose(int x, int y)
{
    this->xAxis = x;
    this->yAxis = y;
    this->symbol = NULL;

}
