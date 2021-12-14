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
	//the chekcing
	return true;
}