#pragma once

#include "piece.h"
#include <string>

class Rook : public Piece
{
public:
	Rook(const int x, const int y, const bool color);
	~Rook();
	virtual bool CheckMovePiece(const int srcX, const int srcY, const int dstX, const int dstY, Board board);
};