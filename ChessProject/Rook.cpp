#include "Rook.h"

Rook::Rook(const int x, const int y, const int color) : Piece(x, y, color)
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
