#include "Knight.h"

Knight::Knight(const int& x, const int& y, const int& color) : Piece(x, y, color)
{
	if (color)
	{//checking for a white or a black because colors are bool
		symbol = 'N';
	}
	else
	{
		symbol = 'n';
	}
}

Knight::~Knight()
{
	//nothing to free
}

bool Knight::CheckMovePiece(const int srcX, const int srcY, const int dstX, const int dstY, Board board)
{
	if ((abs(dstY - srcY) == 2 && abs(dstX - srcX) == 1 ||  // if it goes up or down
		abs(dstX - srcX) == 2 && abs(dstY - srcY) == 1)) // if it goes left or right) 
	{
		return true;
	}
	return false;
}
