#include "King.h"

King::King(const int x, const int y, const bool color) : Piece(x, y, color)
{
	if (color)
	{
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
			else if (((srcX + x) == dstX) && ((srcY + y) == dstY) && // if its the position were looking for
				(board.getSpecificPiece(dstX, dstY) == nullptr || board.getSpecificPiece(dstX, dstY)->getColor() != board.getSpecificPiece(srcX, srcY)->getColor()))
			{ // and its not the same color
				return true;
			}
		}
	}
	return false;
}