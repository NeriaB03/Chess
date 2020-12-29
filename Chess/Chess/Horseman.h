#pragma once
#include "Piece.h"

class Horseman : public Piece
{
public:
	Horseman(std::string type, int col, int row, Board& board,int index,int player);
	~Horseman();
	virtual bool checkIfWinner() const;
	virtual int move(std::string to, int player);
	virtual int checkMove(std::string to, int player);
};