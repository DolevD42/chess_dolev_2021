#pragma once
#include "piece.h"
class Rook : public Piece
{
public:
	Rook(const int x, const int y, const int color);
	~Rook();
	std::string movePiece(std::string mov, Board& board);
};