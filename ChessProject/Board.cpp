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
			v1.push_back(NULL); //initializing the board with Null
		}
		bd.push_back(v1);
	}
	this->board = bd;
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
	if (board[x][y] && p)
	{
		delete board[x][y];
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
				boardString += "#"; //# is the symbol for null
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
			std::cout << boardStr[j+i*BOARD_SIZE]; //print the specific panel
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
	int k = 0;
	int x = 0;
	int y = 0;
	for (i = 0; i < BOARD_SIZE; i++)
	{
		for (j = 0; j < BOARD_SIZE; j++)
		{
			if (board[i][j]) //find a not empty panel
			{
				if (board[i][j]->getColor() != whoToCheck) //check if the panel is the oppsite color
				{
					if (board[i][j]->getSymbol() == 'P' || board[i][j]->getSymbol() == 'p')
					{
						if (board[i][j]->getColor()) //there is 2 different checks, depends the color of the pawn
						{
							if ((i + 1) < BOARD_SIZE && (i + 1) >= 0 && (j + 1) <  BOARD_SIZE && (j + 1) >= 0)
							{
								if (board[i + 1][j + 1])
								{
									if (board[i + 1][j + 1]->getColor() == whoToCheck && (board[i + 1][j + 1]->getSymbol() == 'K' || board[i + 1][j + 1]->getSymbol() == 'k'))
									{
										returnValue = true;
									}
								}
							}
							if ((i - 1) < BOARD_SIZE && (i - 1) >= 0 && (j + 1) < BOARD_SIZE && (j + 1) >= 0)
							{
								if (board[i - 1][j + 1])
								{
									if (board[i - 1][j + 1]->getColor() == whoToCheck && (board[i - 1][j + 1]->getSymbol() == 'K' || board[i - 1][j + 1]->getSymbol() == 'k'))
									{
										returnValue = true;
									}
								}
							}
						}
						else //for each color, its check the 2 spots that the pawn threating on them
						{
							if ((i + 1) < BOARD_SIZE && (i + 1) >= 0 && (j - 1) < BOARD_SIZE && (j - 1) >= 0)
							{
								if (board[i + 1][j - 1])
								{
									if (board[i + 1][j - 1]->getColor() == whoToCheck && (board[i + 1][j - 1]->getSymbol() == 'K' || board[i + 1][j - 1]->getSymbol() == 'k'))
									{
										returnValue = true;
									}
								}
							}
							if ((i - 1) < BOARD_SIZE && (i - 1) >= 0 && (j - 1) < BOARD_SIZE && (j - 1) >= 0)
							{
								if (board[i - 1][j - 1])
								{
									if (board[i - 1][j - 1]->getColor() == whoToCheck && (board[i - 1][j - 1]->getSymbol() == 'K' || board[i - 1][j - 1]->getSymbol() == 'k'))
									{
										returnValue = true;
									}
								}
							}
						}
					}
					if (board[i][j]->getSymbol() == 'B' || board[i][j]->getSymbol() == 'b')
					{
						for (k = 1; i + k < BOARD_SIZE && j + k < BOARD_SIZE; k++)
						{
							if (board[i + k][j + k])
							{
								if (board[i + k][j + k]->getColor() == whoToCheck && (board[i + k][j + k]->getSymbol() == 'k' || board[i + k][j + k]->getSymbol() == 'K'))
								{
									returnValue = true;
								}
								else
								{
									break;
								}
							}
						}
						for (k = 1; i + k < BOARD_SIZE && j - k >= 0; k++)
						{
							if (board[i + k][j - k])
							{
								if (board[i + k][j - k]->getColor() == whoToCheck && (board[i + k][j - k]->getSymbol() == 'k' || board[i + k][j - k]->getSymbol() == 'K'))
								{
									returnValue = true;
								}
								else
								{
									break;
								}
							}
						}
						for (k = 1; i - k >= 0 && j + k < BOARD_SIZE; k++)
						{
							if (board[i - k][j + k])
							{
								if (board[i - k][j + k]->getColor() == whoToCheck && (board[i - k][j + k]->getSymbol() == 'k' || board[i - k][j + k]->getSymbol() == 'K'))
								{
									returnValue = true;
								}
								else
								{
									break;
								}
							}
						}
						for (k = 1; i - k >= 0 && j - k >= 0; k++)
						{
							if (board[i - k][j - k])
							{
								if (board[i - k][j - k]->getColor() == whoToCheck && (board[i - k][j - k]->getSymbol() == 'k' || board[i - k][j - k]->getSymbol() == 'K'))
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
					if (board[i][j]->getSymbol() == 'N' || board[i][j]->getSymbol() == 'n')
					{
						for (x = -2 ; x <= 2; x++)
						{
							for (y = -2; y <= 2; y++)
							{
								if ((i+x) >= BOARD_SIZE || (i + x) < 0 || (j + y) >= BOARD_SIZE || (j + y) < 0 || (abs(x)+abs(y))!= 3) //check that the number don't overflowd, and that its a valid knight move
								{
									continue;
								}
								if (board[i + x][j + y])
								{
									if (board[i+x][j+y]->getColor() == whoToCheck && (board[i+x][j+y]->getSymbol() == 'K' || board[i+x][j+y]->getSymbol() == 'k'))
									{
										returnValue = true;
									}
								}
							}
						}
					}
					if (board[i][j]->getSymbol() == 'Q' || board[i][j]->getSymbol() == 'q')
					{
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
						for (k = i - 1; k >= 0; k--)
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
								if (board[i][k]->getColor() == whoToCheck && (board[i][k]->getSymbol() == 'k' || board[i][k]->getSymbol() == 'K'))
								{
									returnValue = true;
								}
								else
								{
									break;
								}
							}
						}
						for (k = j - 1; k >= 0; k--)
						{
							if (board[i][k])
							{
								if (board[i][k]->getColor() == whoToCheck && (board[i][k]->getSymbol() == 'k' || board[i][k]->getSymbol() == 'K'))
								{
									returnValue = true;
								}
								else
								{
									break;
								}
							}
						}
						for (k = 1; i + k < BOARD_SIZE && j + k < BOARD_SIZE; k++)
						{
							if (board[i + k][j + k])
							{
								if (board[i + k][j + k]->getColor() == whoToCheck && (board[i + k][j + k]->getSymbol() == 'k' || board[i + k][j + k]->getSymbol() == 'K'))
								{
									returnValue = true;
								}
								else
								{
									break;
								}
							}
						}
						for (k = 1; i + k < BOARD_SIZE && j - k >= 0; k++)
						{
							if (board[i + k][j - k])
							{
								if (board[i + k][j - k]->getColor() == whoToCheck && (board[i + k][j - k]->getSymbol() == 'k' || board[i + k][j - k]->getSymbol() == 'K'))
								{
									returnValue = true;
								}
								else
								{
									break;
								}
							}
						}
						for (k = 1; i - k >= 0 && j + k < BOARD_SIZE; k++)
						{
							if (board[i - k][j + k])
							{
								if (board[i - k][j + k]->getColor() == whoToCheck && (board[i - k][j + k]->getSymbol() == 'k' || board[i - k][j + k]->getSymbol() == 'K'))
								{
									returnValue = true;
								}
								else
								{
									break;
								}
							}
						}
						for (k = 1; i - k >= 0 && j - k >= 0; k++)
						{
							if (board[i - k][j - k])
							{
								if (board[i - k][j - k]->getColor() == whoToCheck && (board[i - k][j - k]->getSymbol() == 'k' || board[i - k][j - k]->getSymbol() == 'K'))
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
						for (k = i - 1; k >= 0; k--)
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
								if (board[i][k]->getColor() == whoToCheck && (board[i][k]->getSymbol() == 'k' || board[i][k]->getSymbol() == 'K'))
								{
									returnValue = true;
								}
								else
								{
									break;
								}
							}
						}
						for (k = j - 1; k >= 0; k--)
						{
							if (board[i][k])
							{
								if (board[i][k]->getColor() == whoToCheck && (board[i][k]->getSymbol() == 'k' || board[i][k]->getSymbol() == 'K'))
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
					if (board[i][j]->getSymbol() == 'k' || board[i][j]->getSymbol() == 'K')
					{
						for (int x = -1; x < 2; x++)
						{
							for (int y = -1; y < 2; y++)
							{
								if ((x == 0) && (y == 0))
								{ // if its not the king
									continue;
								}
								if ((i + x) >= BOARD_SIZE || (i + x) < 0 || (j + y) >= BOARD_SIZE || (j + y) < 0) //check that the number don't overflowd
								{
									continue;
								}
								else if (board[i+x][j+y]) 
								{
									if (board[i + x][j + y]->getColor() == whoToCheck && (board[i + x][j + y]->getSymbol() == 'k' || board[i + x][j + y]->getSymbol() == 'K'))
									{
										returnValue = true;
									}
								}
							}
						}
					}
				}
			}
		}
	}
	if (returnValue && (turn != whoToCheck))
	{
		if (temp)
		{
			delete temp;
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
	std::string returnString = board[srcX][srcY]->CheckMovesValidation(srcX, srcY, dstX, dstY, *this); //check the first few things
	if (returnString[0] != 'n')
	{
		return returnString;
	}

	if (!board[srcX][srcY]->CheckMovePiece(srcX, srcY, dstX, dstY, *this)) //check the move of each Piece
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