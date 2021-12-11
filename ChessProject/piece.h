#pragma once
#include "board.h"
#include "stdafx.h"


class Piece
{
protected:
	int color; //0  white 1 black  #insted of using the  color color that i dont have
	int xAxis;
	int yAxis;
	//char symbol; // can be used if we want insted of type()
public:
	Piece(const int x, const int y, const int color);
	~Piece();
	virtual std::string movePiece(std::string STmovDS, Board& board) = 0;//we can use this function as int not string because we return the int of the error and not ther error itself
	virtual std::string* CheckMovesValidation(Board& board) = 0;//didnt understand why we return bool how can we understand what kind of error is this
};