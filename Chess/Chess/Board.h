#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <map>

class Board
{
public:
	Board(std::string board);
	//char** getBoard() const;
	char getBoard(int row,int col) const;
	void printBoard() const;
	//void setBoard(std::string board);
	void setBoard(int row, int col, char piece);
	//void setIndexInBoard(int index, char whatToReplaceWith);
private:
	//std::string _board;
	char _board[8][8];
};