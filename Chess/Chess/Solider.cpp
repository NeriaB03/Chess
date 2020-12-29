#include "Solider.h"

Solider::Solider(std::string type, int col, int row, Board& board,int index,int player):Piece(type,col,row,board,index,player)
{
    this->_isAlreadyMoved = false;
}

Solider::~Solider()
{
}

bool Solider::checkIfWinner() const
{
    return false;
}

int Solider::move(std::string to, int player)
{
    return checkMove(to,player);
}

int Solider::checkMove(std::string to, int player)
{
    int rows = 8 * ((int)(to.at(3)) - 48);
    int rowsFrom = 8 * ((int)(to.at(1)) - 48);
    int cols = (int)(to.at(2)) - 96;
    int colsFrom = (int)(to.at(0)) - 96;

    if (this->_board[0].getBoard((rowsFrom / 8) - 1, colsFrom - 1) == '#' || player != this->_whichPlayer) return 2;
    if (player == 0) {
        if (rows <= rowsFrom) {
            return 6;
        }
        else if (cols != colsFrom) {
            if (cols == colsFrom + 1) {
                if (rows == rowsFrom + 8) {
                    if (islower(this->_board[0].getBoard((rows / 8) - 1, cols - 1))) {
                        this->changeBoard((rows / 8) - 1, cols - 1, (rowsFrom / 8) - 1, colsFrom - 1, 'P');
                        this->setIsAlreadyMoved(true);
                        this->setCol(cols);
                        this->setRow(rows / 8);
                        return 9;
                    }
                    else return 6;
                }
                return 6;
            }
            else if (cols == colsFrom - 1) {
                if (rows == rowsFrom + 8) {
                    if (islower(this->_board[0].getBoard((rows / 8) - 1, cols - 1))) {
                        this->changeBoard((rows / 8) - 1, cols - 1, (rowsFrom / 8) - 1, colsFrom - 1, 'P');
                        this->setIsAlreadyMoved(true);
                        this->setCol(cols);
                        this->setRow(rows / 8);
                        return 9;
                    }
                    else return 6;
                }
                return 6;
            }
            else {
                return 6;
            }
        }
        else if (rows == rowsFrom + 16) {
            if (this->_isAlreadyMoved) return 6;
            if (this->_board[0].getBoard((rows / 8) - 1, cols - 1) == '#') {
                if (this->_board[0].getBoard((rows / 8) - 2, cols - 1 == '#')) {
                    this->changeBoard((rows / 8) - 1, cols - 1, (rowsFrom / 8) - 1, colsFrom - 1, 'P');
                    this->setIsAlreadyMoved(true);
                    this->setCol(cols);
                    this->setRow(rows / 8);
                    return 0;
                }
                else {
                    return 6;
                }
            }
            else {
                return 3;
            }
        }
        else if (rows == rowsFrom + 8) {
            if (this->_board[0].getBoard((rows / 8) - 1, cols - 1) == '#') {
                this->changeBoard((rows / 8) - 1, cols - 1, (rowsFrom / 8) - 1, colsFrom - 1, 'P');
                this->setIsAlreadyMoved(true);
                this->setCol(cols);
                this->setRow(rows / 8);
                return 0;
            }
            else {
                return 3;
            }
        }
        else {
            return 6;
        }
    }
    else {
        if (rows >= rowsFrom) {
            return 6;
        }
        else if (cols != colsFrom) {
            if (cols == colsFrom + 1) {
                if (rows == rowsFrom - 8) {
                    if (isupper(this->_board[0].getBoard((rows / 8) - 1, cols - 1))) {
                        this->changeBoard((rows / 8) - 1, cols - 1, (rowsFrom / 8) - 1, colsFrom - 1, 'p');
                        this->setIsAlreadyMoved(true);
                        this->setCol(cols);
                        this->setRow(rows / 8);
                        return 9;
                    }
                    else return 6;
                }
                return 6;
            }
            else if(cols == colsFrom - 1) {
                if (rows == rowsFrom - 8) {
                    if (isupper(this->_board[0].getBoard((rows / 8) - 1, cols - 1))) {
                        this->changeBoard((rows / 8) - 1, cols - 1, (rowsFrom / 8) - 1, colsFrom - 1, 'p');
                        this->setIsAlreadyMoved(true);
                        this->setCol(cols);
                        this->setRow(rows / 8);
                        return 9;
                    }
                    else return 6;
                }
                return 6;
            }
            else {
                return 6;
            }
        }
        else if (rows == rowsFrom - 16) {
            if (this->_isAlreadyMoved) return 6;
            if (this->_board[0].getBoard((rows / 8) - 1, cols - 1) == '#') {
                if (this->_board[0].getBoard((rows / 8), cols - 1 == '#')) {
                    this->changeBoard((rows / 8) - 1, cols - 1, (rowsFrom / 8) - 1, colsFrom - 1, 'p');
                    this->setIsAlreadyMoved(true);
                    this->setCol(cols);
                    this->setRow(rows / 8);
                    return 0;
                }
                else {
                    return 6;
                }
            }
            else {
                return 3;
            }
        }
        else if (rows == rowsFrom - 8) {
            if (this->_board[0].getBoard((rows / 8) - 1, cols - 1) == '#') {
                this->changeBoard((rows / 8) - 1, cols - 1, (rowsFrom / 8) - 1, colsFrom - 1, 'p');
                this->setIsAlreadyMoved(true);
                this->setCol(cols);
                this->setRow(rows / 8);
                return 0;
            }
            else {
                return 3;
            }
        }
        else {
            return 6;
        }
    }
}

void Solider::setIsAlreadyMoved(bool isAlreadyMoved)
{
    this->_isAlreadyMoved = isAlreadyMoved;
}
