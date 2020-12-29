#include "Turret.h"

Turret::Turret(std::string type, int col, int row, Board& board,int index,int player):Piece(type,col,row,board,index,player)
{
}

Turret::~Turret()
{
}

bool Turret::checkIfWinner() const
{
    return false;
}

int Turret::move(std::string to, int player)
{
    int rows = 8 * ((int)(to.at(3)) - 48);
    int rowsFrom = 8 * ((int)(to.at(1)) - 48);
    int cols = (int)(to.at(2)) - 96;
    int colsFrom = (int)(to.at(0)) - 96;
    int result = Move::turretMove(to, player, this->_board[0], this->_col, this->_row, this->_whichPlayer);
    if (player == 0) {
        if (result == 0 || result == 9) {
            this->setCol(cols);
            this->setRow(rows / 8);
            this->changeBoard((rows / 8) - 1, cols - 1, (rowsFrom / 8) - 1, colsFrom - 1, 'R');
        }
    }
    else {
        if (result == 0 || result == 9) {
            this->setCol(cols);
            this->setRow(rows / 8);
            this->changeBoard((rows / 8) - 1, cols - 1, (rowsFrom / 8) - 1, colsFrom - 1, 'r');
        }
    }
    return result;
}