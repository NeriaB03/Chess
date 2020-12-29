#include "Horseman.h"

Horseman::Horseman(std::string type, int col, int row, Board& board,int index,int player):Piece(type, col, row, board,index,player)
{
}

Horseman::~Horseman()
{
}

bool Horseman::checkIfWinner() const
{
    return false;
}

int Horseman::move(std::string to, int player)
{
    return checkMove(to,player);
}

int Horseman::checkMove(std::string to, int player)
{
    int rows = 8 * ((int)(to.at(3)) - 48);
    int rowsFrom = 8 * ((int)(to.at(1)) - 48);
    int cols = (int)(to.at(2)) - 96;
    int colsFrom = (int)(to.at(0)) - 96;

    if (this->_board[0].getBoard((rowsFrom / 8) - 1, colsFrom - 1) == '#' || player != this->_whichPlayer) return 2;
    if(player == 0){
        if ((rows == (this->_row * 8) + 16 && cols == this->_col + 1) || (rows == (this->_row * 8) + 8 && cols == this->_col + 2)
            || (rows == (this->_row * 8) - 8 && cols == this->_col + 2) || (rows == (this->_row * 8) - 16 && cols == this->_col + 1)
            || (rows == (this->_row * 8) - 16 && cols == this->_col - 1) || (rows == (this->_row * 8) - 8 && cols == this->_col - 2)
            || (rows == (this->_row * 8) + 8 && cols == this->_col - 2) || (rows == (this->_row * 8) + 16 && cols == this->_col - 1)) {
            if (this->_board[0].getBoard((rows / 8) - 1, cols - 1) == '#') {
                this->setCol(cols);
                this->setRow(rows / 8);
                this->changeBoard((rows / 8) - 1, cols - 1, (rowsFrom / 8) - 1, colsFrom - 1, 'N');
                return 0;
            }
            else if (islower(this->_board[0].getBoard((rows / 8) - 1, cols - 1))) {
                this->setCol(cols);
                this->setRow(rows / 8);
                this->changeBoard((rows / 8) - 1, cols - 1, (rowsFrom / 8) - 1, colsFrom - 1, 'N');
                return 9;
            }
            else return 3;
        }
        else return 6;
    }
    else {
        if ((rows == (this->_row * 8) + 16 && cols == this->_col + 1) || (rows == (this->_row * 8) + 8 && cols == this->_col + 2)
            || (rows == (this->_row * 8) - 8 && cols == this->_col + 2) || (rows == (this->_row * 8) - 16 && cols == this->_col + 1)
            || (rows == (this->_row * 8) - 16 && cols == this->_col - 1) || (rows == (this->_row * 8) - 8 && cols == this->_col - 2)
            || (rows == (this->_row * 8) + 8 && cols == this->_col - 2) || (rows == (this->_row * 8) + 16 && cols == this->_col - 1)) {
            if (this->_board[0].getBoard((rows / 8) - 1, cols - 1) == '#') {
                this->setCol(cols);
                this->setRow(rows / 8);
                this->changeBoard((rows / 8) - 1, cols - 1, (rowsFrom / 8) - 1, colsFrom - 1, 'n');
                return 0;
            }
            else if (isupper(this->_board[0].getBoard((rows / 8) - 1, cols - 1))) {
                this->setCol(cols);
                this->setRow(rows / 8);
                this->changeBoard((rows / 8) - 1, cols - 1, (rowsFrom / 8) - 1, colsFrom - 1, 'n');
                return 9;
            }
            else return 3;
        }
        else return 6;
    }
}
