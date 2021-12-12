#include "board.h"
Board::Board()
{
	std::vector<std::vector<Piece*>> board;
	int i = 0;
	int j = 0;
	for (i = 0; i < BOARD_SIZE; i++)
	{
		std::vector<Piece*> v1;
		for (j = 0; j < BOARD_SIZE; j++)
		{
			v1.push_back(NULL);
		}
		board.push_back(v1);
	}
	Rook rookW1 = Rook(0, 0, true);
	board[0][0] = &rookW1;
	Rook rookW2 = Rook(0, 7, true);
	board[0][7] = &rookW2;
	Rook rookB1 = Rook(7, 0, false);
	board[7][0] = &rookB1;
	Rook rookB2 = Rook(7, 7, false);
	board[7][7] = &rookB2;

	King kingW = King(0, 3, true);
	board[0][3] = &kingW;
	King kingB = King(7, 3, false);
	board[7][3] = &kingB;
}

Board::~Board()
{
	//nothing to free cause no memory malloced
}

Piece* Board::getSpecificPiece(int const x, int const y)
{
	return board[x][y];
}

bool Board::getTurn() const
{
	return turn;
}

void Board::changeTurn()
{
	turn = !turn;
}

std::string Board::getBoardString() const
{
	int i = 0;
	int j = 0;
	std::string boardString = "";
	for (i = 0; i < BOARD_SIZE; i++)
	{
		for (j = 0; j < BOARD_SIZE; j++)
		{
			if (board[i][j])
			{
				boardString += board[i][j]->getSymbol();
			}
			else
			{
				boardString += "#";
			}
		}
	}
	return boardString;
}

void Board::printBoard() const
{
	int i = 0;
	int j = 0;
	std::string boardStr = getBoardString();
	for (i = 0; i < BOARD_SIZE; i++)
	{
		for (j = 0; j < BOARD_SIZE; j++)
		{
			std::cout << boardStr[j+i*BOARD_SIZE] << std::endl;
		}
		std::cout << std::endl;
	}
}