#pragma once
#include "Piece.h"

class Solider : public Piece
{
public:
	Solider(std::string type, int col, int row, Board& board,int index,int player);
	~Solider();
	virtual bool checkIfWinner() const;
	virtual int move(std::string to, int player);
	virtual int checkMove(std::string to, int player);
	virtual void setIsAlreadyMoved(bool isAlreadyMoved);
private:
	bool _isAlreadyMoved;
};