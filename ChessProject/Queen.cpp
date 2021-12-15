#include "Queen.h"
#include <math.h>

Queen::Queen(const int x, const int y, const bool color) : Piece(x, y, color)
{
	if (color)
	{
		symbol = 'Q';
	}
	else
	{
		symbol = 'q';
	}
}
Queen::~Queen()
{

}
bool Queen::CheckMovePiece(const int srcX, const int srcY, const int dstX, const int dstY, Board board)
{
	int i = 0;
	if (dstX == srcX || dstY == srcY) //check if the piece is the same row or collumm
	{
		if (dstX > srcX)
		{
			for (i = srcX + 1; i < dstX; i++)
			{
				if (board.getSpecificPiece(i, dstY))
				{
					return false;
				}
			}
		}
		if (dstX < srcX)
		{
			for (i = srcX - 1; i > dstX; i--)
			{
				if (board.getSpecificPiece(i, dstY))
				{
					return false;
				}
			}
		}
		if (dstY > srcY)
		{
			for (i = srcY + 1; i < dstY; i++)
			{
				if (board.getSpecificPiece(dstX, i))
				{
					return false;
				}
			}
		}
		if (dstY < srcY)
		{
			for (i = srcY - 1; i > dstY; i--)
			{
				if (board.getSpecificPiece(dstX, i))
				{
					return false;
				}
			}
		}
	}
	else if (std::abs(dstX-srcX) == std::abs(dstY-srcY)) //check the diagonals
	{
		if (dstX > srcX && dstY > srcY)
		{
			for (i = 1; i + srcX < dstX; i++)
			{
				if (board.getSpecificPiece(srcX + i, srcY+i)) //check if there is any one between the queen and the place
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