#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <map>

class Board
{
public:
	Board(std::string board);
	char getBoard(int row,int col) const;
	void printBoard() const;
	void setBoard(int row, int col, char piece);
private:
	char _board[8][8];
};