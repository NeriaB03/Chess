#pragma once
#include "Board.h"
#include "Solider.h"
#include "Turret.h"
#include "Horseman.h"
#include "Runner.h"
#include "Queen.h"
#include "King.h"

#define NUM_OF_SOLIDERS 8
class Piece;
class King;
class Player
{
public:
	Player(const Board& b,int player);
	Player(const Player& p);
	~Player();
	int getAlivePieces() const;
	void createPieces();
	void createSolider(Solider* s);
	void createTurret(Turret* t);
	void createHorseman(Horseman* h);
	void createRunner(Runner* r);
	void createQueen(Queen* q);
	void createKing(King* k);
	int getPlayer() const;
	void setPlayer(int player);
	virtual Piece* operator[](int index) const;
	virtual Piece& operator[](char index) const;
	virtual void replaceWithNull(int index);
	void setBoard(int row,int col,char piece);
	virtual char getBoard(int row,int col) const;
	virtual void printBoard() const;
private:
	std::vector<Piece*> _pieces;
	static int _numOfAlivePieces;
	static std::vector<Board> _board;
	int _whichPlayer;
};