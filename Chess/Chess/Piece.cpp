#include "Piece.h"

std::vector<Board> Piece::_board;

Piece::Piece(std::string type, int col, int row, Board& board,int index,int player)
{
	this->_type = type;
	setCol(col);
	setRow(row);
	this->_board.push_back(board);
	this->_index = index;
	this->_whichPlayer = player;
}

Piece::Piece(int col, int row)
{
	this->_col = col;
	this->_row = row;
}

Piece::~Piece()
{
}

std::string Piece::getType() const
{
	return this->_type;
}

void Piece::setCol(int col)
{
	this->_col = col;
}

void Piece::setRow(int row)
{
	this->_row = row;
}

int Piece::getCol() const
{
	return this->_col;
}

int Piece::getRow() const
{
	return this->_row;
}

int Piece::getIndex() const
{
	return this->_index;
}

bool Piece::checkSquare(std::string square)
{
	if ((((int)(square.at(0))-96) == this->getCol()) && (((int)(square.at(1))-48) == this->getRow())) return true;
	return false;
}

void Piece::setSquare(std::string square)
{
	this->setRow(((int)(square.at(3)) - 48));
	this->setCol(((int)(square.at(2)) - 96));
}

void Piece::changeBoard(int row, int col, int rowFrom, int colFrom, char piece)
{
	this->_board[0].setBoard(rowFrom, colFrom, '#');
	this->_board[0].setBoard(row, col, piece);
}

void Piece::changeBoard(int row, int col, char piece)
{
	this->_board[0].setBoard(row, col, piece);
}

char Piece::getBoard(int row, int col)
{
	return this->_board[0].getBoard(row,col);
}

Piece* Piece::operator=(const Piece& other)
{
	if (this != &other){
		*this = other;
	}
	return this;
}
