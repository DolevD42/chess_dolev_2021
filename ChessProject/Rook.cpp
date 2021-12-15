#include "Rook.h"

Rook::Rook(const int x, const int y, const bool color) : Piece(x, y, color)
{
	if (color)
	{
		symbol = 'R';
	}
	else
	{
		symbol = 'r';
	}
}
Rook::~Rook()
{

}
bool Rook::CheckMovePiece(const int srcX, const int srcY, const int dstX, const int dstY, Board board)
{
	int i = 0;
	if (dstX != srcX && dstY != srcY) //check if the piece is the same row or collumm
	{
		return false;
	}
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

	return true; //return true if its work
}