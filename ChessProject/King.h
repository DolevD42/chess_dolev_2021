#pragma once
#include "piece.h"
class King : public Piece
{
public:
	King(const int x, const int y, const bool color);
	~King();
	virtual bool CheckMovePiece(const int srcX, const int srcY, const int dstX, const int dstY, Board board);
};