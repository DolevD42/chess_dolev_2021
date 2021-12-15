#pragma once
#include "piece.h"
class Pawn :
    public Piece
{
public:
	Pawn(const int x, const int y, const bool color);
	~Pawn();
	virtual bool CheckMovePiece(const int srcX, const int srcY, const int dstX, const int dstY, Board board);
};

