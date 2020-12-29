#include "King.h"

King::King(std::string type, int col, int row, Board& board,int index,int player):Piece(type,col,row,board,index,player)
{
}

King::King(int col, int row):Piece(col,row)
{
}

King::~King()
{
}

bool King::checkIfWinner() const
{
	return false;
}

int King::move(std::string to, int player)
{
    int rows = 8 * ((int)(to.at(3)) - 48);
    int rowsFrom = 8 * ((int)(to.at(1)) - 48);
    int cols = (int)(to.at(2)) - 96;
    int colsFrom = (int)(to.at(0)) - 96;
    int result = Move::kingMove(to, player, this->_board[0], this->_col, this->_row, this->_whichPlayer);
    if (player == 0) {
        if (result == 0 || result == 9) {
            this->setCol(cols);
            this->setRow(rows / 8);
            this->changeBoard((rows / 8) - 1, cols - 1, (rowsFrom / 8) - 1, colsFrom - 1, 'K');
        }
    }
    else {
        if (result == 0 || result == 9) {
            this->setCol(cols);
            this->setRow(rows / 8);
            this->changeBoard((rows / 8) - 1, cols - 1, (rowsFrom / 8) - 1, colsFrom - 1, 'k');
        }
    }
    return result;
}

int King::checkCheck(Player& other, std::string to)
{
    bool checkFlag = false;
    bool matFlag = false;
    std::string square = "";
    for (int i = 0; i < 16; i++) {
        if (other[i] != nullptr) {
            if (other.getPlayer() == 0) {
                if (i != 3) {
                    square += (char)(other[i]->getCol() + 96);
                    square += (char)(other[i]->getRow() + 48);
                    square += to;
                    if (other[i]->move(square, 0) == 0 || other[i]->move(square, 0) == 9) {
                        checkFlag = true;
                        break;
                    }
                }
            }
            else {
                if (i != 3) {
                    square += (char)(other[i]->getCol() + 96);
                    square += (char)(other[i]->getRow() + 48);
                    square += to;
                    if (other[i]->move(square, 1) == 0 || other[i]->move(square, 0) == 9) {
                        checkFlag = true;
                        break;
                    }
                }
            }
        }
    }

    if (checkFlag) {
        matFlag = checkMat(other,to);
        if (matFlag) return 2;
        return 1;
    }
    return 0;
}

bool King::checkMat(Player& other, std::string to)
{
    return false;
}
