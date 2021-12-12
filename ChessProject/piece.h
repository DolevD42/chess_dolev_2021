#pragma once
#include "board.h"
class board;

#include "stdafx.h"

class Piece
{
protected:
	bool color;
	int xAxis;
	int yAxis;
	char symbol;
public:
	Piece(const int x, const int y, const int color);
	~Piece();
	virtual std::string movePiece(std::string STmovDS, Board& board) = 0;
	std::string CheckMovesValidation(const int srcX, const int srcY, const int dstX, const int dstY, Board& board);
	char getSymbol() const;
	int getX() const;
	int getY() const;
	void setPose(int x, int y);
	bool getColor() const;
};