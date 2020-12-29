#pragma once
#include "Piece.h"

class Runner : public Piece
{
public:
	Runner(std::string type, int col, int row, Board& board,int index,int player);
	virtual ~Runner();
	virtual bool checkIfWinner() const;
	virtual int move(std::string to, int player);
};