#include "Queen.h"

Queen::Queen(std::string type, int col, int row, Board& board,int index,int player):Piece(type,col,row,board,index,player)
{
}

Queen::~Queen()
{
}

bool Queen::checkIfWinner() const
{
	return false;
}

int Queen::move(std::string to, int player)
{
	return checkMove(to,player);
}

int Queen::checkMove(std::string to, int player)
{
	return 2;
}
