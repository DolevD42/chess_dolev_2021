/*
This file servers as an example of how to use Pipe.h file.
It is recommended to use the following code in your project,
in order to read and write information from and to the Backend
*/

#include "Pipe.h"
#include "board.h"
#include "piece.h"
#include "Rook.h"
#include "King.h"
#include "Queen.h"
#include "Knight.h"
#include "Bishop.h"
#include "Pawn.h"
#include <iostream>
#include <thread>


using std::cout;
using std::endl;
using std::string;


void main()
{
	std::string move = "";
	std::string code = "";
	Board b = Board();

	Pawn* PawnW1 = new Pawn(0, 1, true);
	b.setSpecificPiece(0, 1, PawnW1);
	Pawn* PawnW2 = new Pawn(1, 1, true);
	b.setSpecificPiece(1, 1, PawnW2);
	Pawn* PawnW3 = new Pawn(2, 1, true);
	b.setSpecificPiece(2, 1, PawnW3);
	Pawn* PawnW4 = new Pawn(3, 1, true);
	b.setSpecificPiece(3, 1, PawnW4);
	Pawn* PawnW5 = new Pawn(4, 1, true);
	b.setSpecificPiece(4, 1, PawnW5);
	Pawn* PawnW6 = new Pawn(5, 1, true);
	b.setSpecificPiece(5, 1, PawnW6);
	Pawn* PawnW7 = new Pawn(6, 1, true);
	b.setSpecificPiece(6, 1, PawnW7);
	Pawn* PawnW8 = new Pawn(7, 1, true);
	b.setSpecificPiece(7, 1, PawnW8);

	Pawn* PawnB1 = new Pawn(0, 6, false);
	b.setSpecificPiece(0, 6, PawnB1);
	Pawn* PawnB2 = new Pawn(1, 6, false);
	b.setSpecificPiece(1, 6, PawnB2);
	Pawn* PawnB3 = new Pawn(2, 6, false);
	b.setSpecificPiece(2, 6, PawnB3);
	Pawn* PawnB4 = new Pawn(3, 6, false);
	b.setSpecificPiece(3, 6, PawnB4);
	Pawn* PawnB5 = new Pawn(4, 6, false);
	b.setSpecificPiece(4, 6, PawnB5);
	Pawn* PawnB6 = new Pawn(5, 6, false);
	b.setSpecificPiece(5, 6, PawnB6);
	Pawn* PawnB7 = new Pawn(6, 6, false);
	b.setSpecificPiece(6, 6, PawnB7);
	Pawn* PawnB8 = new Pawn(7, 6, false);
	b.setSpecificPiece(7, 6, PawnB8);

	Bishop* BishopW1 = new Bishop(2, 0, true);
	b.setSpecificPiece(2, 0, BishopW1);
	Bishop* BishopW2 = new Bishop(5, 0, true);
	b.setSpecificPiece(5, 0, BishopW2);
	Bishop* BishopB1 = new Bishop(2, 7, false);
	b.setSpecificPiece(2, 7, BishopB1);
	Bishop* BishopB2 = new Bishop(5, 7, false);
	b.setSpecificPiece(5, 7, BishopB2);

	Knight* KnightW1 = new Knight(1, 0, true);
	b.setSpecificPiece(1, 0, KnightW1);
	Knight* KnightW2 = new Knight(6, 0, true);
	b.setSpecificPiece(6, 0, KnightW2);
	Knight* KnightB1 = new Knight(1, 7, false);
	b.setSpecificPiece(1, 7, KnightB1);
	Knight* KnightB2 = new Knight(6, 7, false);
	b.setSpecificPiece(6, 7, KnightB2);

	Rook* rookW1 = new Rook(0, 0, true);
	b.setSpecificPiece(0, 0 , rookW1);
	Rook* rookW2 = new Rook(7, 0, true);
	b.setSpecificPiece(7, 0, rookW2);
	Rook* rookB1 = new Rook(0, 7, false);
	b.setSpecificPiece(0, 7, rookB1);
	Rook* rookB2 = new Rook(7, 7, false);
	b.setSpecificPiece(7, 7, rookB2);

	King* kingW = new King(3, 0, true);
	b.setSpecificPiece(3, 0, kingW);
	King* kingB = new King(3, 7, false);
	b.setSpecificPiece(3, 7, kingB);
	
	Queen* QueenW = new Queen(4, 0, true);
	b.setSpecificPiece(4, 0, QueenW);
	Queen* QueenB = new Queen(4, 7, false);
	b.setSpecificPiece(4, 7, QueenB);
	std::cout << " " << std::endl;
	b.printBoard();
	/*
	while (true)
	{
		std::cout << "Whats Your move? ";
		std::cin >> move;
		code = b.movePieceOnBoard(move);
		if (code[0] == '0' || code[0] == '1')
		{
			if (code[0] == '1')
			{
				std::cout << "There is a check! (code 1)" << std::endl;
			}
			else
			{
				std::cout << "code 0" << std::endl;
			}
			b.printBoard();
			b.changeTurn();
		}
		else
		{
			std::cout << "Your move is not valid and his code is ";
			std::cout << code[0] << std::endl;
		}
		
	}
	
	*/
	srand(time_t(NULL));


	Pipe p;
	bool isConnect = p.connect();

	string ans;
	while (!isConnect)
	{
		cout << "cant connect to graphics" << endl;
		cout << "Do you try to connect again or exit? (0-try again, 1-exit)" << endl;
		std::cin >> ans;

		if (ans == "0")
		{
			cout << "trying connect again.." << endl;
			Sleep(5000);
			isConnect = p.connect();
		}
		else
		{
			p.close();
			return;
		}
	}

	
	char msgToGraphics[1024];
	// msgToGraphics should contain the board string accord the protocol
	// YOUR CODE
	std::string boardStr = b.getBoardString();
	boardStr = boardStr += "0";
	
	strcpy_s(msgToGraphics, "rnbkqbnrpppppppp################################PPPPPPPPRNBKQBNR1"); // just example...
	int i = 0;
	for (i = 0; i < 65; i++)
	{
		msgToGraphics[i] = boardStr[i];
	}
	p.sendMessageToGraphics(msgToGraphics);   // send the board string

	// get message from graphics
	string msgFromGraphics = p.getMessageFromGraphics();

	while (msgFromGraphics != "quit")
	{
		// should handle the string the sent from graphics
		// according the protocol. Ex: e2e4           (move e2 to e4)
		
		strcpy_s(msgToGraphics, "YOUR CODE"); // msgToGraphics should contain the result of the operation
		
		

		// JUST FOR EREZ DEBUGGING
		int r = rand() % 10; // just for debugging......
		msgToGraphics[0] = (char)(1 + '0');
		msgToGraphics[1] = 0;
		// JUST FOR EREZ DEBUGGING

		code = b.movePieceOnBoard(msgFromGraphics);
		msgToGraphics[0] = code[0];
		msgToGraphics[1] = NULL;
		// return result to graphics		
		p.sendMessageToGraphics(msgToGraphics);
		if (code[0] == '0' || code[0] == '1')
		{
			if (code[0] == '1')
			{
				std::cout << "There is a check!" << std::endl;
			}
			b.printBoard();
			b.changeTurn();
		}
		// get message from graphics
		msgFromGraphics = p.getMessageFromGraphics();
	}
	
	p.close();
}