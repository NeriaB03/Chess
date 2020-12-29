#include "Runner.h"

Runner::Runner(std::string type, int col, int row, Board& board,int index,int player):Piece(type,col,row,board,index,player)
{
}

Runner::~Runner()
{
}

bool Runner::checkIfWinner() const
{
	return false;
}

int Runner::move(std::string to, int player)
{
	return checkMove(to,player);
}

int Runner::checkMove(std::string to, int player)
{
    int rows = 8 * ((int)(to.at(3)) - 48);
    int rowsFrom = 8 * ((int)(to.at(1)) - 48);
    int cols = (int)(to.at(2)) - 96;
    int colsFrom = (int)(to.at(0)) - 96;

    if (this->_board[0].getBoard((rowsFrom / 8) - 1, colsFrom - 1) == '#' || player != this->_whichPlayer) return 2;
    if (player == 0) {
        for (int i = 0; i < abs(cols - colsFrom) - 1; i++) {
            if (rows > rowsFrom) {
                if (cols > colsFrom) {
                    if (this->_board[0].getBoard((rowsFrom / 8) + i, colsFrom + i) != '#') {
                        return 3;
                    }
                }
                else {
                    if (this->_board[0].getBoard((rowsFrom / 8) + i, colsFrom - i) != '#') {
                        return 3;
                    }
                }
            }
            else {
                if (cols > colsFrom) {
                    if (this->_board[0].getBoard((rowsFrom / 8) - i, colsFrom + i) != '#') {
                        return 3;
                    }
                }
                else {
                    if (this->_board[0].getBoard((rowsFrom / 8) - i, colsFrom - i) != '#') {
                        return 3;
                    }
                }
            }
        }
        if (this->_board[0].getBoard((rows / 8) - 1, cols - 1) == '#') {
            if (abs((rows / 8) - (rowsFrom / 8)) == abs(cols - colsFrom)) {
                this->setCol(cols);
                this->setRow(rows / 8);
                this->changeBoard((rows / 8) - 1, cols - 1, (rowsFrom / 8) - 1, colsFrom - 1, 'B');
                return 0;
            }
            else return 6;
        }
        else if (islower(this->_board[0].getBoard((rows / 8) - 1, cols - 1))) {
            if (abs((rows / 8) - (rowsFrom / 8)) == abs(cols - colsFrom)) {
                this->setCol(cols);
                this->setRow(rows / 8);
                this->changeBoard((rows / 8) - 1, cols - 1, (rowsFrom / 8) - 1, colsFrom - 1, 'B');
                return 9;
            }
            else return 6;
        }
        else return 3;
    }
    else {
        if (this->_board[0].getBoard((rows / 8) - 1, cols - 1) == '#') {
            if (abs((rows / 8) - (rowsFrom / 8)) == abs(cols - colsFrom)) {
                this->setCol(cols);
                this->setRow(rows / 8);
                this->changeBoard((rows / 8) - 1, cols - 1, (rowsFrom / 8) - 1, colsFrom - 1, 'b');
                return 0;
            }
            else return 6;
        }
        else if (isupper(this->_board[0].getBoard((rows / 8) - 1, cols - 1))) {
            if (abs((rows / 8) - (rowsFrom / 8)) == abs(cols - colsFrom)) {
                this->setCol(cols);
                this->setRow(rows / 8);
                this->changeBoard((rows / 8) - 1, cols - 1, (rowsFrom / 8) - 1, colsFrom - 1, 'b');
                return 9;
            }
            else return 6;
        }
        else return 3;
    }
}
