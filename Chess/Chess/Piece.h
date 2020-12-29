#pragma once
#include "Board.h"

class Piece
{
public:
	Piece(std::string type, int col, int row, Board& board,int index,int player);
	Piece(int col, int row);
	~Piece();
	virtual bool checkIfWinner() const = 0;
	virtual std::string getType() const;
	virtual int move(std::string to, int player) = 0;
	virtual int checkMove(std::string to, int player) = 0;
	virtual void setCol(int col);
	virtual void setRow(int row);
	virtual int getCol() const;
	virtual int getRow() const;
	virtual int getIndex() const;
	virtual bool checkSquare(std::string square);
	virtual void setSquare(std::string square);
	virtual void changeBoard(int row, int col,int rowFrom,int colFrom, char piece);
	virtual void changeBoard(int row, int col, char piece);
	virtual char getBoard(int row, int col);
	virtual Piece* operator=(const Piece& other);
protected:
	std::string _type;
	int _col;
	int _row;
	static std::vector<Board> _board;
	int _index;
	int _whichPlayer;
};