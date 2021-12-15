#pragma once
#include "piece.h"
class Bishop :
	public Piece
{
public:
	Bishop(const int x, const int y, const bool color);
	~Bishop();
	virtual bool CheckMovePiece(const int srcX, const int srcY, const int dstX, const int dstY, Board board);
};

