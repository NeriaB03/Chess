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
    return checkMove(to,player);
}

int Turret::checkMove(std::string to, int player)
{
    int rows = 8 * ((int)(to.at(3)) - 48);
    int rowsFrom = 8 * ((int)(to.at(1)) - 48);
    int cols = (int)(to.at(2)) - 96;
    int colsFrom = (int)(to.at(0)) - 96;

    if (this->_board[0].getBoard((rowsFrom / 8) - 1, colsFrom - 1) == '#' || player != this->_whichPlayer) return 2;
    if (player == 0) {
        if ((this->_col == cols && this->_row != rows / 8) || (this->_row == rows / 8 && this->_col != cols)) {
            if (this->_board[0].getBoard((rows / 8) - 1, cols - 1) == '#' || islower(this->_board[0].getBoard((rows / 8) - 1, cols - 1))) {
                if (colsFrom == cols) {
                    if (rowsFrom < rows) {
                        for (int i = (rowsFrom / 8) + 1; i <= (rows / 8); i++) {
                            if (i == rows / 8 && islower(this->_board[0].getBoard(i - 1, cols - 1))) {
                                this->setCol(cols);
                                this->setRow(rows / 8);
                                this->changeBoard((rows / 8) - 1, cols - 1, (rowsFrom / 8) - 1, colsFrom - 1, 'R');
                                return 9;//return 9 for eaten
                            }
                            //else if (isupper(this->_board[0].getBoard(i-1,cols-1))) {
                            else if(this->_board[0].getBoard(i-1,cols-1) != '#'){
                                return 3;
                            }
                            else if (i == rows / 8 && this->_board[0].getBoard(i - 1, cols - 1) == '#') {
                                this->changeBoard((rows / 8) - 1, cols - 1, (rowsFrom / 8) - 1, colsFrom - 1, 'R');
                                return 0;
                            }
                        }
                    }
                    else {
                        for (int i = rowsFrom / 8 - 1; i >= rows / 8 - rowsFrom / 8; i--) {
                            if (i == rows / 8 && islower(this->_board[0].getBoard(i - 1, cols - 1))) {
                                this->setCol(cols);
                                this->setRow(rows / 8);
                                this->changeBoard((rows / 8) - 1, cols - 1, (rowsFrom / 8) - 1, colsFrom - 1, 'R');
                                return 9;//return 9 for eaten
                            }
                            //else if (isupper(this->_board[0].getBoard(i-1,cols-1))) {
                            else if (this->_board[0].getBoard(i - 1, cols - 1) != '#') {
                                return 3;
                            }
                            else if (i == rows / 8 && this->_board[0].getBoard(i - 1, cols - 1) == '#') {
                                this->changeBoard((rows / 8) - 1, cols - 1, (rowsFrom / 8) - 1, colsFrom - 1, 'R');
                                return 0;
                            }
                        }
                    }
                }
                else {
                    if (colsFrom < cols) {
                        for (int i = colsFrom + 1; i <= cols; i++) {
                            if (i == cols && islower(this->_board[0].getBoard(rows - 1, i - 1))) {
                                this->setCol(cols);
                                this->setRow(rows / 8);
                                this->changeBoard((rows / 8) - 1, cols - 1, (rowsFrom / 8) - 1, colsFrom - 1, 'R');
                                return 9;//return 9 for eaten
                            }
                            //else if (isupper(this->_board[0].getBoard(rows-1,i-1))) {
                            else if (this->_board[0].getBoard(rows - 1, i - 1) != '#') {
                                return 3;
                            }
                            else if (i == cols && this->_board[0].getBoard(rows - 1, i - 1) == '#') {
                                this->changeBoard((rows / 8) - 1, cols - 1, (rowsFrom / 8) - 1, colsFrom - 1, 'R');
                                return 0;
                            }
                        }
                    }
                    else {
                        for (int i = colsFrom - 1; i >= cols; i--) {
                            if (i == cols && islower(this->_board[0].getBoard(rows - 1, i - 1))) {
                                this->setCol(cols);
                                this->setRow(rows / 8);
                                this->changeBoard((rows / 8) - 1, cols - 1, (rowsFrom / 8) - 1, colsFrom - 1, 'R');
                                return 9;//return 9 for eaten
                            }
                            //else if (isupper(this->_board[0].getBoard(rows-1,i-1))) {
                            else if (this->_board[0].getBoard(rows - 1, i - 1) != '#') {
                                return 3;
                            }
                            else if (i == cols && this->_board[0].getBoard(rows - 1, i - 1) == '#') {
                                this->changeBoard((rows / 8) - 1, cols - 1, (rowsFrom / 8) - 1, colsFrom - 1, 'R');
                                return 0;
                            }
                        }
                    }
                }
                this->setCol(cols);
                this->setRow(rows / 8);
                this->changeBoard((rows / 8) - 1, cols - 1, (rowsFrom / 8) - 1, colsFrom - 1, 'R');
                return 0;
            }
            else return 3;
        }
        else if (this->_row == rows / 8 && this->_col == cols) return 7;
        else if (this->_row != rows / 8 && this->_col != cols) return 6;
    }
    else {
        if ((this->_col == cols && this->_row != rows / 8) || (this->_row == rows / 8 && this->_col != cols)) {
            if (this->_board[0].getBoard((rows / 8) - 1, cols - 1) == '#' || isupper(this->_board[0].getBoard((rows / 8) - 1, cols - 1))) {
                if (colsFrom == cols) {
                    if (rowsFrom < rows) {
                        for (int i = rowsFrom / 8 + 1; i <= rows / 8 - rowsFrom / 8; i++) {
                            if (i == rows / 8 && isupper(this->_board[0].getBoard(i - 1, cols - 1))) {
                                this->setCol(cols);
                                this->setRow(rows / 8);
                                this->changeBoard((rows / 8) - 1, cols - 1, (rowsFrom / 8) - 1, colsFrom - 1, 'r');
                                return 9;//return 9 for eaten
                            }
                            //else if (islower(this->_board[0].getBoard(i - 1, cols - 1))) {
                            else if(this->_board[0].getBoard(i-1,cols-1) != '#'){
                                return 3;
                            }
                            else if (i == rows / 8 && this->_board[0].getBoard(i - 1, cols - 1) == '#') {
                                this->changeBoard((rows / 8) - 1, cols - 1, (rowsFrom / 8) - 1, colsFrom - 1, 'r');
                                return 0;
                            }
                        }
                    }
                    else {
                        for (int i = rowsFrom / 8 - 1; i >= rows / 8 - rowsFrom / 8; i--) {
                            if (i == rows / 8 && isupper(this->_board[0].getBoard(i - 1, cols - 1))) {
                                this->setCol(cols);
                                this->setRow(rows / 8);
                                this->changeBoard((rows / 8) - 1, cols - 1, (rowsFrom / 8) - 1, colsFrom - 1, 'r');
                                return 9;//return 9 for eaten
                            }
                            //else if (islower(this->_board[0].getBoard(i - 1, cols - 1))) {
                            else if (this->_board[0].getBoard(i - 1, cols - 1) != '#') {
                                return 3;
                            }
                            else if (i == rows / 8 && this->_board[0].getBoard(i - 1, cols - 1) == '#') {
                                this->changeBoard((rows / 8) - 1, cols - 1, (rowsFrom / 8) - 1, colsFrom - 1, 'r');
                                return 0;
                            }
                        }
                    }
                }
                else {
                    if (colsFrom < cols) {
                        for (int i = colsFrom + 1; i <= cols; i++) {
                            if (i == cols && isupper(this->_board[0].getBoard(rows - 1, i - 1))) {
                                this->setCol(cols);
                                this->setRow(rows / 8);
                                this->changeBoard((rows / 8) - 1, cols - 1, (rowsFrom / 8) - 1, colsFrom - 1, 'r');
                                return 9;//return 9 for eaten
                            }
                            //else if (islower(this->_board[0].getBoard(rows - 1, i - 1))) {
                            else if (this->_board[0].getBoard(rows - 1, i - 1) != '#') {
                                return 3;
                            }
                            else if (i == cols && this->_board[0].getBoard(rows - 1, i - 1) == '#') {
                                this->changeBoard((rows / 8) - 1, cols - 1, (rowsFrom / 8) - 1, colsFrom - 1, 'r');
                                return 0;
                            }
                        }
                    }
                    else {
                        for (int i = colsFrom - 1; i >= cols; i--) {
                            if (i == cols && isupper(this->_board[0].getBoard(rows - 1, i - 1))) {
                                this->setCol(cols);
                                this->setRow(rows / 8);
                                this->changeBoard((rows / 8) - 1, cols - 1, (rowsFrom / 8) - 1, colsFrom - 1, 'r');
                                return 9;//return 9 for eaten
                            }
                            //else if (islower(this->_board[0].getBoard(rows - 1, i - 1))) {
                            else if (this->_board[0].getBoard(rows - 1, i - 1) != '#') {
                                return 3;
                            }
                            else if (i == cols && this->_board[0].getBoard(rows - 1, i - 1) == '#') {
                                this->changeBoard((rows / 8) - 1, cols - 1, (rowsFrom / 8) - 1, colsFrom - 1, 'r');
                                return 0;
                            }
                        }
                    }
                }
                this->setCol(cols);
                this->setRow(rows / 8);
                this->changeBoard((rows / 8) - 1, cols - 1, (rowsFrom / 8) - 1, colsFrom - 1, 'r');
                return 0;
            }
            else return 3;
        }
        else if (this->_row == rows / 8 && this->_col == cols) return 7;
        else if (this->_row != rows / 8 && this->_col != cols) return 6;
    }
}