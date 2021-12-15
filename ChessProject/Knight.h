#pragma once
#include "piece.h"

class Knight :
	public Piece
{
public:
	Knight(const int& x, const int& y, const int& color);
	~Knight();
	virtual bool CheckMovePiece(const int srcX, const int srcY, const int dstX, const int dstY, Board board);


};