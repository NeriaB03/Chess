/*
This file servers as an example of how to use Pipe.h file.
It is recommended to use the following code in your project, 
in order to read and write information from and to the Backend
*/

#include "Pipe.h"
#include <iostream>
#include <thread>
#include "Manager.h"
#include "Board.h"
#include <string>

using std::cout;
using std::endl;
using std::string;


void main()
{
	srand(time_t(NULL));

	
	Pipe p;
	bool isConnect = p.connect();
	
	Board b("RNBKQBNRPPPPPPPP################################pppppppprnbkqbnr0");
	Player* p1 = new Player(b, 0);
	Player* p2 = new Player(b, 1);
	Player tempP1(b,0);
	Player tempP2(b,1);
	Manager m(0, p1, p2);

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
	
	int currPlayer = 0;
	char msgToGraphics[1024];
	// msgToGraphics should contain the board string accord the protocol
	// YOUR CODE

	strcpy_s(msgToGraphics, "rnbkqbnrpppppppp################################PPPPPPPPRNBKQBNR0"); // just example...
	//strcpy_s(msgToGraphics, "r##k###r################################################R##K###R0"); // just example...
	
	p.sendMessageToGraphics(msgToGraphics);   // send the board string

	// get message from graphics
	string msgFromGraphics = p.getMessageFromGraphics();

	while (msgFromGraphics != "quit")
	{
		// should handle the string the sent from graphics
		// according the protocol. Ex: e2e4           (move e2 to e4)

		// YOUR CODE
		int result = 0;
		//Player tempP1(*p1);
		//Player tempP2(*p2);

		int rows = 8 * ((int)(msgFromGraphics.at(3)) - 48);
		int rowsFrom = 8 * ((int)(msgFromGraphics.at(1)) - 48);

		int indexInBoard = rowsFrom - (int)(msgFromGraphics.at(0)) + 96 + 7;

		bool isMoved = false;
		bool isCalledMoved = false;
		int index = 0;

		if (currPlayer == 0) {
			for (int i = 0; i < 16; i++) {
				if (tempP1[i] != nullptr) {
					if (tempP1[i]->checkSquare(msgFromGraphics)) {
						result = tempP1[i]->move(msgFromGraphics, currPlayer);
						if(result == 0 || result == 9) isMoved = true;
						isCalledMoved = true;
						index = i;
						break;
					}
				}
			}
		}
		else {
			for (int i = 0; i < 16; i++) {
				if (tempP2[i] != nullptr) {
					if (tempP2[i]->checkSquare(msgFromGraphics)) {
						result = tempP2[i]->move(msgFromGraphics, currPlayer);
						if (result == 0) isMoved = true;
						isCalledMoved = true;
						index = i;
						break;
					}
				}
			}
		}

		if (!isMoved && result == 0 && !isCalledMoved) result = 2;

		if (result == 9) {
			if (currPlayer == 0) {
				for (int i = 0; i < 16; i++) {
					if (tempP2[i] != nullptr) {
						if(tempP2[i]->getCol() == tempP1[index]->getCol() && tempP2[i]->getRow() == tempP1[index]->getRow()){
							p2->replaceWithNull(i);
							tempP2.replaceWithNull(i);
							break;
						}
					}
				}
			}
			else {
				for (int i = 0; i < 16; i++) {
					if (tempP1[i] != nullptr) {
						if (tempP2[index]->getCol() == tempP1[i]->getCol() && tempP2[index]->getRow() == tempP1[i]->getRow()) {
							p1->replaceWithNull(i);
							tempP1.replaceWithNull(i);
							break;
						}
					}
				}
			}
			result = 0;
		}
		if (isMoved) {
			if (currPlayer == 0) {
				tempP1[index]->setSquare(msgFromGraphics);
				for (int i = 0; i < 16; i++) {
					for (int j = 0; j < 8; j++) {
						for (int k = 0; k < 8; k++) {
							if(tempP1[i] != nullptr) tempP1[i]->changeBoard(j, k, tempP1[index]->getBoard(j, k));
							if(tempP2[i] != nullptr) tempP2[i]->changeBoard(j, k, tempP1[index]->getBoard(j, k));
						}
					}
				}
			}
			else {
				tempP2[index]->setSquare(msgFromGraphics);
				for (int i = 0; i < 16; i++) {
					for (int j = 0; j < 8; j++) {
						for (int k = 0; k < 8; k++) {
							if (tempP1[i] != nullptr) tempP1[i]->changeBoard(j, k, tempP2[index]->getBoard(j, k));
							if (tempP2[i] != nullptr) tempP2[i]->changeBoard(j, k, tempP2[index]->getBoard(j, k));
						}
					}
				}
			}
		}

		std::string s = std::to_string(result);
		char const* pchar = s.c_str();  //use char const* as target type

		strcpy_s(msgToGraphics, pchar); // msgToGraphics should contain the result of the operation

		/******* JUST FOR EREZ DEBUGGING ******/
		//int r = rand() % 10; // just for debugging......
		//msgToGraphics[0] = (char)(1 + '0');
		//msgToGraphics[1] = 0;
		/******* JUST FOR EREZ DEBUGGING ******/

		// return result to graphics		
		p.sendMessageToGraphics(msgToGraphics);

		// get message from graphics
		msgFromGraphics = p.getMessageFromGraphics();

		//check for check
		Player tempPlayer1(tempP1);
		Player tempPlayer2(tempP2);
		std::string to = "e1";
		if (currPlayer == 0) {
			King k(tempP2[3]->getCol(), tempP2[3]->getRow());
			if (k.checkCheck(tempPlayer2,to) == 1) result = 1;
			else if (k.checkCheck(tempPlayer2,to) == 2) result = 8;
		}
		else {
			King k(tempP1[3]->getCol(), tempP1[3]->getRow());
			if (k.checkCheck(tempPlayer1,to) == 1) result = 1;
			else if (k.checkCheck(tempPlayer1,to) == 2) result = 8;
		}

		if (result == 0 || result == 1) //only if the player succesfuly moved piece pass the turn
		{
			if (currPlayer == 1) {
				currPlayer = 0;
				for (int i = 0; i < 8; i++) {
					for (int j = 0; j < 8; j++) {
						tempP1[0]->changeBoard(i,j,tempP2[0]->getBoard(i,j));
					}
				}	
			}
			else {
				currPlayer = 1;
				for (int i = 0; i < 8; i++) {
					for (int j = 0; j < 8; j++) {
						tempP2[0]->changeBoard(i, j, tempP1[0]->getBoard(i, j));
					}
				}
			}
			for (int i = 0; i < 8; i++) {
				for (int j = 0; j < 8; j++) {
					p1->setBoard(i, j, tempP1.getBoard(i, j));
					p2->setBoard(i, j, tempP2.getBoard(i, j));
				}
			}
		}
		else if (result == 8) {
			if (currPlayer == 0) std::cout << "White wins";
			else std::cout << "Black wins";
		}
	}

	p.close();
}




/*

		if (result == 0) {
			if (currPlayer == 1) {
				for (int i = 0; i < 8; i++) {
					for (int j = 0; j < 8; j++) {
						tempP1[0]->changeBoard(i, j, tempP2[0]->getBoard(i, j));
					}
				}
			}
			else {
				for (int i = 0; i < 8; i++) {
					for (int j = 0; j < 8; j++) {
						tempP2[0]->changeBoard(i, j, tempP1[0]->getBoard(i, j));
					}
				}
			}
			for (int i = 0; i < 8; i++) {
				for (int j = 0; j < 8; j++) {
					p1->setBoard(i, j, tempP1.getBoard(i, j));
					p2->setBoard(i, j, tempP2.getBoard(i, j));
				}
			}
		}

		//check for check
		if (result == 0) {
			Player tempPlayer1(tempP1);
			Player tempPlayer2(tempP2);
			std::string to;
			if (currPlayer == 0) {
				to += (char)(tempP2[3]->getCol() + 96);
				to += (char)(tempP2[3]->getRow() + 48);
				King k(tempP2[3]->getCol(), tempP2[3]->getRow());
				if (k.checkCheck(tempPlayer1, to) == 1) result = 1;
				else if (k.checkCheck(tempPlayer1, to) == 2) result = 8;
			}
			else {
				to += (char)(tempP1[3]->getCol());
				to += (char)(tempP1[3]->getRow());
				King k(tempP1[3]->getCol(), tempP1[3]->getRow());
				if (k.checkCheck(tempPlayer2, to) == 1) result = 1;
				else if (k.checkCheck(tempPlayer2, to) == 2) result = 8;
			}
		}

		std::string s = std::to_string(result);
		char const* pchar = s.c_str();  //use char const* as target type

		strcpy_s(msgToGraphics, pchar); // msgToGraphics should contain the result of the operation

		// return result to graphics
		p.sendMessageToGraphics(msgToGraphics);

		// get message from graphics
		msgFromGraphics = p.getMessageFromGraphics();
		if (result == 0) {
			if (currPlayer == 0) currPlayer = 1;
			else currPlayer = 0;
		}
		else if (result == 1) {
			if (currPlayer == 0) currPlayer = 1;
			else currPlayer = 0;
			if (currPlayer == 0) std::cout << "Black is in check";
			else std::cout << "White is in check";
		}
		else if (result == 8) {
			if (currPlayer == 0) std::cout << "White wins";
			else std::cout << "Black wins";
		}

*/