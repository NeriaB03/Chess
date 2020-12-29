#pragma once
#include "Piece.h"

class Turret : public Piece
{
public:
	Turret(std::string type, int col, int row, Board& board,int index,int player);
	~Turret();
	virtual bool checkIfWinner() const;
	virtual int move(std::string to, int player);
	virtual int checkMove(std::string to, int player);
};