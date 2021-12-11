#pragma once
#include "stdafx.h"
#include <iostream>
#include <vector>


class Board
{
private:
	std::vector<std::vector<Piece*>> board;
	bool turn;
public:
	Board();
	~Board();
	std::string getBoardString() const;
	Piece* getSpecificPiece(int const x, int const y);
	bool getTurn() const;
	void changeTurn();
	void printBoard() const;
	bool checkForCheck(bool const whoToCheck, int const xSrc, int const ySrc, int const xDst,int const yDst);

	
};