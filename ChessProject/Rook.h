#pragma once
#include "piece.h"
class Rook : public Piece
{
public:
	Rook();
	~Rook();
	std::string movePiece(std::string mov, Board& board);
};