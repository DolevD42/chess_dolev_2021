#include "King.h"

King::King(const int x, const int y, const int color) : Piece(x, y, color)
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
