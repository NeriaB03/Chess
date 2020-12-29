#include "Board.h"

Board::Board(std::string board)
{
	//setBoard(board);
	this->_board[0][0] = 'R';
	this->_board[0][1] = 'N';
	this->_board[0][2] = 'B';
	this->_board[0][3] = 'Q';
	this->_board[0][4] = 'K';
	this->_board[0][5] = 'B';
	this->_board[0][6] = 'N';
	this->_board[0][7] = 'R';
	this->_board[1][0] = 'P';
	this->_board[1][1] = 'P';
	this->_board[1][2] = 'P';
	this->_board[1][3] = 'P';
	this->_board[1][4] = 'P';
	this->_board[1][5] = 'P';
	this->_board[1][6] = 'P';
	this->_board[1][7] = 'P';
	for (int i = 2; i < 6; i++) {
		for (int j = 0; j < 8; j++) {
			this->_board[i][j] = '#';
		}
	}
	this->_board[6][0] = 'p';
	this->_board[6][1] = 'p';
	this->_board[6][2] = 'p';
	this->_board[6][3] = 'p';
	this->_board[6][4] = 'p';
	this->_board[6][5] = 'p';
	this->_board[6][6] = 'p';
	this->_board[6][7] = 'p';
	this->_board[7][0] = 'r';
	this->_board[7][1] = 'n';
	this->_board[7][2] = 'b';
	this->_board[7][3] = 'k';
	this->_board[7][4] = 'q';
	this->_board[7][5] = 'b';
	this->_board[7][6] = 'n';
	this->_board[7][7] = 'r';
}

//char** Board::getBoard() const
//{
//	return this->_board;
//}

char Board::getBoard(int row,int col) const
{
	return this->_board[row][col];
}

void Board::printBoard() const
{
	for (int i = 0; i < 64; i++) {
		std::cout << this->_board[i];
		if ((i + 1) % 8 == 0) std::cout << std::endl;
	}
}

//void Board::setBoard(std::string board)
//{
//	this->_board = board;
//}

void Board::setBoard(int row, int col, char piece)
{
	this->_board[row][col] = piece;
}

//void Board::setIndexInBoard(int index, char whatToReplaceWith)
//{
//	this->_board.at(index) = whatToReplaceWith;
//}
