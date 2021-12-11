#pragma once
#include "stdafx.h"
#include <iostream>
class Board
{
public:
	Piece** board;//board[][] doesnt work
	bool* arrayChess;
	bool* arrayTurn;
	Board(const std::string& startingBoard);
	~Board();
	//std::string getBoardString(); didnt understand why we need get when we initilize it on the constructor
	void printBoard() const;
	//check for check didnt done
};