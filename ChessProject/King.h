#pragma once
#include "piece.h"
class King : public Piece
{
public:
	King(const int x, const int y, const int color);
	~King();
	std::string movePiece(std::string mov, Board& board);
};