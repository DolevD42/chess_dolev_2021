#pragma once
#include "stdafx.h"
#include "piece.h"
class Piece;

#include <iostream>
#include <vector>
#include <string>
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
	void setSpecificPiece(int const x, int const y, Piece* p);
	bool getTurn() const;
	void changeTurn();
	void printBoard() const;
	bool checkForCheck(bool const whoToCheck, int const srcX, int const srcY, int const dstX, int const dstY);
	std::string movePieceOnBoard(std::string mov);

	
};