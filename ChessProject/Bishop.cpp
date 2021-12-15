#include "Bishop.h"
#include <math.h>

Bishop::Bishop(const int x, const int y, const bool color) : Piece(x, y, color)
{
	if (color)
	{
		symbol = 'B';
	}
	else
	{
		symbol = 'b';
	}
}
Bishop::~Bishop()
{

}
bool Bishop::CheckMovePiece(const int srcX, const int srcY, const int dstX, const int dstY, Board board)
{
	int i = 0;
	if (std::abs(dstX - srcX) == std::abs(dstY - srcY)) //check the diagonals
	{
		if (dstX > srcX && dstY > srcY)
		{
			for (i = 1; i + srcX < dstX; i++)
			{
				if (board.getSpecificPiece(srcX + i, srcY + i)) //check if there is any one between the the bishop and the place
				{
					return false;
				}
			}
		}
		if (dstX > srcX && dstY < srcY)
		{
			for (i = 1; i + srcX < dstX; i++)
			{
				if (board.getSpecificPiece(srcX + i, srcY - i))
				{
					return false;
				}
			}
		}
		if (dstX < srcX && dstY > srcY)
		{
			for (i = 1; -i + srcX > dstX; i++)
			{
				if (board.getSpecificPiece(srcX - i, srcY + i))
				{
					return false;
				}
			}
		}
		if (dstX < srcX && dstY < srcY)
		{
			for (i = 1; -i + srcX > dstX; i++)
			{
				if (board.getSpecificPiece(srcX - i, srcY - i))
				{
					return false;
				}
			}
		}
	}
	else
	{
		return false;
	}
	return true; //return true if its work
}