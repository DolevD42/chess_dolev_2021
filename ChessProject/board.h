#pragma once
#include "stdafx.h"
#include "piece.h"
#include "Rook.h"
#include "King.h"
class piece;
#include <iostream>
#include <vector>

#define BOARD_SIZE 8

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