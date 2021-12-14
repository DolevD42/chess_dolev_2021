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
	b.printBoard();
	Rook rookW1 = Rook(0, 0, true);
	b.setSpecificPiece(0, 0 , &rookW1);
	Rook rookW2 = Rook(7, 0, true);
	b.setSpecificPiece(7, 0, &rookW2);
	Rook rookB1 = Rook(0, 7, false);
	b.setSpecificPiece(0, 7, &rookB1);
	Rook rookB2 = Rook(7, 7, false);
	b.setSpecificPiece(7, 7, &rookB2);

	King kingW = King(3, 0, true);
	b.setSpecificPiece(3, 0, &kingW);
	King kingB = King(3, 7, false);
	b.setSpecificPiece(3, 7, &kingB);
	std::cout<< " " <<std::endl;
	b.printBoard();
	
	while (true)
	{
		std::cout << "Whats Your move? ";
		std::cin >> move;
		code = b.movePieceOnBoard(move);
		if (code[0] == '0' || code[0] == '1')
		{
			if (code[0] == '1')
			{
				std::cout << "There is a check!" << std::endl;
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

	

	/*srand(time_t(NULL));


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

	strcpy_s(msgToGraphics, "rnbkqbnrpppppppp################################PPPPPPPPRNBKQBNR1"); // just example...

	p.sendMessageToGraphics(msgToGraphics);   // send the board string

	// get message from graphics
	string msgFromGraphics = p.getMessageFromGraphics();

	while (msgFromGraphics != "quit")
	{
		// should handle the string the sent from graphics
		// according the protocol. Ex: e2e4           (move e2 to e4)

		// YOUR CODE
		strcpy_s(msgToGraphics, "YOUR CODE"); // msgToGraphics should contain the result of the operation

		// JUST FOR EREZ DEBUGGING
		int r = rand() % 10; // just for debugging......
		msgToGraphics[0] = (char)(1 + '0');
		msgToGraphics[1] = 0;
		// JUST FOR EREZ DEBUGGING


		// return result to graphics		
		p.sendMessageToGraphics(msgToGraphics);

		// get message from graphics
		msgFromGraphics = p.getMessageFromGraphics();
	}

	p.close();*/
}