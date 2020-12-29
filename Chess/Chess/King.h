#pragma once
#include "Piece.h"
#include "Player.h"

class Player;
class King : public Piece
{
public:
	King(std::string type, int col, int row, Board& board,int index,int player);
	King(int col, int row);
	~King();
	virtual bool checkIfWinner() const;
	virtual int move(std::string to, int player);
	virtual int checkCheck(Player& other,std::string to);
	virtual bool checkMat(Player& other, std::string to);
};