#include "King.h"

King::King(const int x, const int y, const bool color) : Piece(x, y, color)
{
	if (color)
	{//checking for a white or a black because colors are bool
		symbol = 'K';
	}
	else
	{
		symbol = 'k';
	}
}

King::~King()
{

}
bool King::CheckMovePiece(const int srcX, const int srcY, const int dstX, const int dstY, Board board)
{
	for (int x = -1; x < 2; x++)
	{
		for (int y = -1; y < 2; y++) 
		{
			if ((x == 0) && (y == 0)) 
			{ // if its not the king
				continue;
			}
			else if ((srcX+x) == dstX && (srcY+y) == dstY)
			{
				return true;
			}
		}
	}
	return false;
}