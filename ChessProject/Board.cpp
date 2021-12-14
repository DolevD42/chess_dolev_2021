#include "board.h"
Board::Board()
{
	std::vector<std::vector<Piece*>> bd;
	int i = 0;
	int j = 0;
	for (i = 0; i < BOARD_SIZE; i++)
	{
		std::vector<Piece*> v1;
		for (j = 0; j < BOARD_SIZE; j++)
		{
			v1.push_back(NULL);
		}
		bd.push_back(v1);
	}
	this->board = bd;
	/*Rook rookW1 = Rook(0, 0, true);
	board[0][0] = &rookW1;
	Rook rookW2 = Rook(0, 7, true);
	board[0][7] = &rookW2;
	Rook rookB1 = Rook(7, 0, false);
	board[7][0] = &rookB1;
	Rook rookB2 = Rook(7, 7, false);
	board[7][7] = &rookB2;*/

	/*King kingW = King(0, 3, true);
	board[0][3] = &kingW;
	King kingB = King(7, 3, false);
	board[7][3] = &kingB; */
	turn = true;
}

Board::~Board()
{
	//nothing to free cause no memory malloced
}

Piece* Board::getSpecificPiece(int const x, int const y)
{
	return board[x][y];
}

void Board::setSpecificPiece(int const x, int const y, Piece* p)
{
	if (board[x][y])
	{
		//delete the peace
	}
	board[x][y] = p;
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
			if (board[j][i])
			{
				boardString += board[j][i]->getSymbol();
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
			std::cout << boardStr[j+i*BOARD_SIZE];
			std::cout << " ";
		}
		std::cout << std::endl;
	}
}

bool Board::checkForCheck(bool const whoToCheck, int const srcX, int const srcY, int const dstX, int const dstY)
{
	bool returnValue = false;
	Piece* temp = board[dstX][dstY];
	board[dstX][dstY] = board[srcX][srcY];
	board[srcX][srcY] = NULL;
	int i = 0;
	int j = 0;
	for (i = 0; i < BOARD_SIZE; i++)
	{
		for (j = 0; j < BOARD_SIZE; j++)
		{
			if (board[i][j])
			{
				if (board[i][j]->getColor() != whoToCheck)
				{
					if (board[i][j]->getSymbol() == 'R' || board[i][j]->getSymbol() == 'r')
					{
						int k = 0;
						for (k = i + 1; k < BOARD_SIZE; k++)
						{
							if (board[k][j])
							{
								if (board[k][j]->getColor() == whoToCheck && (board[k][j]->getSymbol() == 'K' || board[k][j]->getSymbol() == 'k'))
								{
									returnValue = true;
								}
								else
								{
									break;
								}
							}
						}
						for (k = i - 1; k > 0; k--)
						{
							if (board[k][j])
							{
								if (board[k][j]->getColor() == whoToCheck && (board[k][j]->getSymbol() == 'K' || board[k][j]->getSymbol() == 'k'))
								{
									returnValue = true;
								}
								else
								{
									break;
								}
							}
						}
						for (k = j + 1; k < BOARD_SIZE; k++)
						{
							if (board[i][k])
							{
								if (board[i][k]->getColor() == whoToCheck && (board[i][k]->getSymbol() == 'K' || board[i][k]->getSymbol() == 'K'))
								{
									returnValue = true;
								}
								else
								{
									break;
								}
							}
						}
						for (k = j - 1; k > 0; k--)
						{
							if (board[i][k])
							{
								if (board[i][k]->getColor() == whoToCheck && (board[i][k]->getSymbol() == 'K' || board[i][k]->getSymbol() == 'K'))
								{
									returnValue = true;
								}
								else
								{
									break;
								}
							}
						}
					}
					if (board[i][j]->getSymbol() == 'K' || board[i][j]->getSymbol() == 'K')
					{
						std::vector<char>* temp = new std::vector<char>;

						// loop for 3 sides for 3 possible moves
						for (int x = -1; x < 2; x++) 
						{
							for (int y = -1; y < 2; y++)
							{
								if (srcX + x >= 0 && dstX + x < BOARD_SIZE && srcY + y >= 0 && dstY + y < BOARD_SIZE)
								{
									
								}
							}
						}

						return temp;
					}
				}
			}
		}
	}
	if (returnValue && (turn != whoToCheck))
	{
		if (temp)
		{
			//delete temp;
		}
		board[dstX][dstY]->setPose(dstX, dstY);
	}
	else
	{
		board[srcX][srcY] = board[dstX][dstY];
		board[dstX][dstY] = temp;
	}
	return returnValue;
	
}

std::string Board::movePieceOnBoard(std::string mov)
{
	int srcX = mov[0] - 'a';
	int srcY = 8 - (mov[1] - '0');
	int dstX = mov[2] - 'a';
	int dstY = 8 - (mov[3] - '0');
	if (srcX < 0 || srcX >= BOARD_SIZE ||
		srcY < 0 || srcY >= BOARD_SIZE ||
		dstX < 0 || dstX >= BOARD_SIZE ||
		dstY < 0 || dstY >= BOARD_SIZE)
	{
		return "5";
	}

	if (!board[srcX][srcY])
	{

		return "2";
	}
	std::string returnString = board[srcX][srcY]->CheckMovesValidation(srcX, srcY, dstX, dstY, *this);
	if (returnString[0] != 'n')
	{
		return returnString;
	}

	if (!board[srcX][srcY]->CheckMovePiece(srcX, srcY, dstX, dstY, *this))
	{
		returnString = "6";
		return returnString;
	}
	
	if (checkForCheck(board[srcX][srcY]->getColor(), srcX, srcY, dstX, dstY))
	{
		returnString = "4";
		return returnString;
	}
	if (checkForCheck(!board[srcX][srcY]->getColor(), srcX, srcY, dstX, dstY))
	{
		returnString = "1";
		return returnString;
	}
	setSpecificPiece(dstX, dstY, getSpecificPiece(srcX, srcY));
	setSpecificPiece(srcX, srcY, NULL);
	board[dstX][dstY]->setPose(dstX, dstY);
	returnString = "0";
	return returnString;
}