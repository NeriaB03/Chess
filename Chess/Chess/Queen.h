#pragma once
#include "Piece.h"

class Queen : public Piece
{
public:
	Queen(std::string type, int col, int row, Board& board,int index,int player);
	~Queen();
	virtual bool checkIfWinner() const;
	virtual int move(std::string to, int player);
	virtual int checkMove(std::string to, int player);
};