#include "Pawn.h"
Pawn::Pawn(const int x, const int y, const bool color) : Piece(x, y, color)
{
	if (color)
	{//checking for a white or a black because colors are bool
		symbol = 'P';
	}
	else
	{
		symbol = 'p';
	}
}

Pawn::~Pawn()
{

}
bool Pawn::CheckMovePiece(const int srcX,const int srcY, const int dstX, const int dstY, Board board)
{
	if (board.getTurn()) //the white turn
	{
		if (srcY == 1 && dstY == 3 && dstX == srcX && !board.getSpecificPiece(dstX, dstY) && !board.getSpecificPiece(dstX, 2)) //check if he can do 2 step move
		{
			return true;
		}
		if (dstY == srcY + 1)
		{
			if (srcX == dstX && !board.getSpecificPiece(dstX, dstY))
			{
				return true;
			}
			if ((srcX + 1 == dstX || srcX - 1 == dstX) && board.getSpecificPiece(dstX, dstY)) //check if he can eat
			{
				return true;
			}
		}
	}
	else // the black turn
	{
		if (srcY == 6 && dstY == 4 && dstX == srcX && !board.getSpecificPiece(dstX, dstY) && !board.getSpecificPiece(dstX, 5)) //check if he can do 2 step move
		{
			return true;
		}
		if (dstY == srcY - 1)
		{
			if (srcX == dstX && !board.getSpecificPiece(dstX, dstY))
			{
				return true;
			}
			if ((srcX + 1 == dstX || srcX - 1 == dstX) && board.getSpecificPiece(dstX, dstY))
			{
				return true;
			}
		}
	}
	return false;
}