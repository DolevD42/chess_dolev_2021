#pragma once
#include "piece.h"
class Queen :
    public Piece
{
public:
	Queen(const int x, const int y, const bool color);
	~Queen();
	virtual bool CheckMovePiece(const int srcX, const int srcY, const int dstX, const int dstY, Board board);
};

