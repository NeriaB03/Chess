#include "Player.h"

int Player::_numOfAlivePieces = 16;
std::vector<Board> Player::_board;

Player::Player(const Board& b,int player)
{
	this->_board.push_back(b);
	this->setPlayer(player);
	this->createPieces();
}

Player::Player(const Player& p)
{
	this->_whichPlayer = p._whichPlayer;
	for (int i = 0; i < 16; i++) {
		this->_pieces.push_back(p._pieces[i]);
	}
}

Player::~Player()
{
	this->_pieces.clear();
}

int Player::getAlivePieces() const
{
	return _numOfAlivePieces;
}

void Player::createPieces()
{
	if (this->_whichPlayer == 0)//if player is white
	{
		this->createTurret(new Turret("Turret", 1, 1, this->_board[0],0,0));
		this->createHorseman(new Horseman("Horseman", 2, 1, this->_board[0],1,0));
		this->createRunner(new Runner("Runner", 3, 1, this->_board[0],2,0));
		this->createKing(new King("King", 4, 1, this->_board[0],3,0));
		this->createQueen(new Queen("Queen", 5, 1, this->_board[0], 4, 0));
		this->createRunner(new Runner("Runner", 6, 1, this->_board[0],5,0));
		this->createHorseman(new Horseman("Horseman", 7, 1, this->_board[0],6,0));
		this->createTurret(new Turret("Turret", 8, 1, this->_board[0],7,0));
		for (int i = 1; i <= NUM_OF_SOLIDERS; i++) this->createSolider(new Solider("Solider", i, 2, this->_board[0],7+i,0));
	}
	else//if player is black
	{
		this->createTurret(new Turret("Turret", 1, 8, this->_board[0],0,1));
		this->createHorseman(new Horseman("Horseman", 2, 8, this->_board[0],1,1));
		this->createRunner(new Runner("Runner", 3, 8, this->_board[0],2,1));
		this->createKing(new King("King", 4, 8, this->_board[0], 3, 1));
		this->createQueen(new Queen("Queen", 5, 8, this->_board[0],4,1));
		this->createRunner(new Runner("Runner", 6, 8, this->_board[0],5,1));
		this->createHorseman(new Horseman("Horseman", 7, 8, this->_board[0],6,1));
		this->createTurret(new Turret("Turret", 8, 8, this->_board[0],7,1));
		for (int i = 1; i <= NUM_OF_SOLIDERS; i++) this->createSolider(new Solider("Solider", i, 7, this->_board[0],7+i,1));
	}
}

void Player::createSolider(Solider* s)
{
	this->_pieces.push_back(s);
}

void Player::createTurret(Turret* t)
{
	this->_pieces.push_back(t);
}

void Player::createHorseman(Horseman* h)
{
	this->_pieces.push_back(h);
}

void Player::createRunner(Runner* r)
{
	this->_pieces.push_back(r);
}

void Player::createQueen(Queen* q)
{
	this->_pieces.push_back(q);
}

void Player::createKing(King* k)
{
	this->_pieces.push_back(k);
}

int Player::getPlayer() const
{
	return this->_whichPlayer;
}

void Player::setPlayer(int player)
{
	this->_whichPlayer = player;
}

Piece* Player::operator[](int index) const
{
	return this->_pieces[index];
}

Piece& Player::operator[](char index) const
{
	return *this->_pieces[index - '0'];
}

void Player::replaceWithNull(int index)
{
	this->_pieces[index] = nullptr;
}

void Player::setBoard(int row, int col, char piece)
{
	this->_board[0].setBoard(row, col, piece);
}

char Player::getBoard(int row, int col) const
{
	return this->_board[0].getBoard(row,col);
}

void Player::printBoard() const
{
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) std::cout << this->_board[0].getBoard(i,j);
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

Board& Player::getBoard() const
{
	return this->_board[0];
}
