#include "piece.h"

bool Piece::getColor() const
{
    return this->color;
}

Piece::Piece(const int x, const int y, const bool color)
{
    this->setPose(x, y);
    this->color = color;
}

Piece::~Piece()
{
    //nothing to free cause no memory malloced
}

std::string Piece::CheckMovesValidation(const int srcX, const int srcY, const int dstX, const int dstY, Board board)
{
   
    if (board.getTurn() != board.getSpecificPiece(srcX, srcY)->getColor())
    {
        return "2";
    }
    if (board.getSpecificPiece(dstX, dstY))
    {
        if (board.getSpecificPiece(dstX, dstY)->getColor() == board.getTurn())
        {
            return "3";
        }
    }
    if (srcX == dstX && srcY == dstY)
    {
        return "7";
    }
    return "n"; //return n if the function didn't find any mistakes
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

}
