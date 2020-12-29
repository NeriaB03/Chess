#include "Move.h"

int Move::turretMove(std::string to, int player,Board board,int pieceCol,int pieceRow,int whichPlayer)
{
    int rows = 8 * ((int)(to.at(3)) - 48);
    int rowsFrom = 8 * ((int)(to.at(1)) - 48);
    int cols = (int)(to.at(2)) - 96;
    int colsFrom = (int)(to.at(0)) - 96;

    if (board.getBoard((rowsFrom / 8) - 1, colsFrom - 1) == '#' || player != whichPlayer) return 2;
    if (player == 0) {
        if ((pieceCol == cols && pieceRow != rows / 8) || (pieceRow == rows / 8 && pieceCol != cols)) {
            if (board.getBoard((rows / 8) - 1, cols - 1) == '#' || islower(board.getBoard((rows / 8) - 1, cols - 1))) {
                if (colsFrom == cols) {
                    if (rowsFrom < rows) {
                        for (int i = (rowsFrom / 8) + 1; i <= (rows / 8); i++) {
                            if (i == rows / 8 && islower(board.getBoard(i - 1, cols - 1))) {
                                return 9;
                            }
                            else if (board.getBoard(i - 1, cols - 1) != '#') {
                                return 3;
                            }
                            else if (i == rows / 8 && board.getBoard(i - 1, cols - 1) == '#') {
                                return 0;
                            }
                        }
                    }
                    else {
                        for (int i = rowsFrom / 8 - 1; i >= rows / 8 - rowsFrom / 8; i--) {
                            if (i == rows / 8 && islower(board.getBoard(i - 1, cols - 1))) {
                                return 9;
                            }
                            else if (board.getBoard(i - 1, cols - 1) != '#') {
                                return 3;
                            }
                            else if (i == rows / 8 && board.getBoard(i - 1, cols - 1) == '#') {
                                return 0;
                            }
                        }
                    }
                }
                else {
                    if (colsFrom < cols) {
                        for (int i = colsFrom + 1; i <= cols; i++) {
                            if (i == cols && islower(board.getBoard(rows - 1, i - 1))) {
                                return 9;
                            }
                            else if (board.getBoard(rows - 1, i - 1) != '#') {
                                return 3;
                            }
                            else if (i == cols && board.getBoard(rows - 1, i - 1) == '#') {
                                return 0;
                            }
                        }
                    }
                    else {
                        for (int i = colsFrom - 1; i >= cols; i--) {
                            if (i == cols && islower(board.getBoard(rows - 1, i - 1))) {
                                return 9;
                            }
                            else if (board.getBoard(rows - 1, i - 1) != '#') {
                                return 3;
                            }
                            else if (i == cols && board.getBoard(rows - 1, i - 1) == '#') {
                                return 0;
                            }
                        }
                    }
                }
                return 0;
            }
            else return 3;
        }
        else if (pieceRow == rows / 8 && pieceCol == cols) return 7;
        else if (pieceRow != rows / 8 && pieceCol != cols) return 6;
    }
    else {
        if ((pieceCol == cols && pieceRow != rows / 8) || (pieceRow == rows / 8 && pieceCol != cols)) {
            if (board.getBoard((rows / 8) - 1, cols - 1) == '#' || isupper(board.getBoard((rows / 8) - 1, cols - 1))) {
                if (colsFrom == cols) {
                    if (rowsFrom < rows) {
                        for (int i = rowsFrom / 8 + 1; i <= rows / 8 - rowsFrom / 8; i++) {
                            if (i == rows / 8 && isupper(board.getBoard(i - 1, cols - 1))) {
                                return 9;
                            }
                            else if (board.getBoard(i - 1, cols - 1) != '#') {
                                return 3;
                            }
                            else if (i == rows / 8 && board.getBoard(i - 1, cols - 1) == '#') {
                                return 0;
                            }
                        }
                    }
                    else {
                        for (int i = rowsFrom / 8 - 1; i >= rows / 8 - rowsFrom / 8; i--) {
                            if (i == rows / 8 && isupper(board.getBoard(i - 1, cols - 1))) {
                                return 9;
                            }
                            else if (board.getBoard(i - 1, cols - 1) != '#') {
                                return 3;
                            }
                            else if (i == rows / 8 && board.getBoard(i - 1, cols - 1) == '#') {
                                return 0;
                            }
                        }
                    }
                }
                else {
                    if (colsFrom < cols) {
                        for (int i = colsFrom + 1; i <= cols; i++) {
                            if (i == cols && isupper(board.getBoard(rows - 1, i - 1))) {
                                return 9;
                            }
                            else if (board.getBoard(rows - 1, i - 1) != '#') {
                                return 3;
                            }
                            else if (i == cols && board.getBoard(rows - 1, i - 1) == '#') {
                                return 0;
                            }
                        }
                    }
                    else {
                        for (int i = colsFrom - 1; i >= cols; i--) {
                            if (i == cols && isupper(board.getBoard(rows - 1, i - 1))) {
                                return 9;
                            }
                            else if (board.getBoard(rows - 1, i - 1) != '#') {
                                return 3;
                            }
                            else if (i == cols && board.getBoard(rows - 1, i - 1) == '#') {
                                return 0;
                            }
                        }
                    }
                }
                return 0;
            }
            else return 3;
        }
        else if (pieceRow == rows / 8 && pieceCol == cols) return 7;
        else if (pieceRow != rows / 8 && pieceCol != cols) return 6;
    }
}

int Move::horsemanMove(std::string to, int player, Board board, int pieceCol, int pieceRow,int whichPlayer)
{
    int rows = 8 * ((int)(to.at(3)) - 48);
    int rowsFrom = 8 * ((int)(to.at(1)) - 48);
    int cols = (int)(to.at(2)) - 96;
    int colsFrom = (int)(to.at(0)) - 96;

    if (board.getBoard((rowsFrom / 8) - 1, colsFrom - 1) == '#' || player != whichPlayer) return 2;
    if (player == 0) {
        if ((rows == (pieceRow * 8) + 16 && cols == pieceCol + 1) || (rows == (pieceRow * 8) + 8 && cols == pieceCol + 2)
            || (rows == (pieceRow * 8) - 8 && cols == pieceCol + 2) || (rows == (pieceRow * 8) - 16 && cols == pieceCol + 1)
            || (rows == (pieceRow * 8) - 16 && cols == pieceCol - 1) || (rows == (pieceRow * 8) - 8 && cols == pieceCol - 2)
            || (rows == (pieceRow * 8) + 8 && cols == pieceCol - 2) || (rows == (pieceRow * 8) + 16 && cols == pieceCol - 1)) {
            if (board.getBoard((rows / 8) - 1, cols - 1) == '#') {
                return 0;
            }
            else if (islower(board.getBoard((rows / 8) - 1, cols - 1))) {
                return 9;
            }
            else return 3;
        }
        else return 6;
    }
    else {
        if ((rows == (pieceRow * 8) + 16 && cols == pieceCol + 1) || (rows == (pieceRow * 8) + 8 && cols == pieceCol + 2)
            || (rows == (pieceRow * 8) - 8 && cols == pieceCol + 2) || (rows == (pieceRow * 8) - 16 && cols == pieceCol + 1)
            || (rows == (pieceRow * 8) - 16 && cols == pieceCol - 1) || (rows == (pieceRow * 8) - 8 && cols == pieceCol - 2)
            || (rows == (pieceRow * 8) + 8 && cols == pieceCol - 2) || (rows == (pieceRow * 8) + 16 && cols == pieceCol - 1)) {
            if (board.getBoard((rows / 8) - 1, cols - 1) == '#') {
                return 0;
            }
            else if (isupper(board.getBoard((rows / 8) - 1, cols - 1))) {
                return 9;
            }
            else return 3;
        }
        else return 6;
    }
}

int Move::runnerMove(std::string to, int player, Board board, int pieceCol, int pieceRow,int whichPlayer)
{
    int rows = 8 * ((int)(to.at(3)) - 48);
    int rowsFrom = 8 * ((int)(to.at(1)) - 48);
    int cols = (int)(to.at(2)) - 96;
    int colsFrom = (int)(to.at(0)) - 96;

    if (board.getBoard((rowsFrom / 8) - 1, colsFrom - 1) == '#' || player != whichPlayer) return 2;
    if (player == 0) {
        for (int i = 0; i < abs(cols - colsFrom) - 1; i++) {
            if (rows > rowsFrom) {
                if (cols > colsFrom) {
                    if (board.getBoard((rowsFrom / 8) + i, colsFrom + i) != '#') {
                        return 3;
                    }
                }
                else {
                    if (board.getBoard((rowsFrom / 8) + i, colsFrom - i) != '#') {
                        return 3;
                    }
                }
            }
            else {
                if (cols > colsFrom) {
                    if (board.getBoard((rowsFrom / 8) - i, colsFrom + i) != '#') {
                        return 3;
                    }
                }
                else {
                    if (board.getBoard((rowsFrom / 8) - i, colsFrom - i) != '#') {
                        return 3;
                    }
                }
            }
        }
        if (board.getBoard((rows / 8) - 1, cols - 1) == '#') {
            if (abs((rows / 8) - (rowsFrom / 8)) == abs(cols - colsFrom)) {
                return 0;
            }
            else return 6;
        }
        else if (islower(board.getBoard((rows / 8) - 1, cols - 1))) {
            if (abs((rows / 8) - (rowsFrom / 8)) == abs(cols - colsFrom)) {
                return 9;
            }
            else return 6;
        }
        else return 3;
    }
    else {
        for (int i = 0; i < abs(cols - colsFrom) - 1; i++) {
            if (rows > rowsFrom) {
                if (cols > colsFrom) {
                    if (board.getBoard((rowsFrom / 8) + i, colsFrom + i) != '#') {
                        return 3;
                    }
                }
                else {
                    if (board.getBoard((rowsFrom / 8) + i, colsFrom - i) != '#') {
                        return 3;
                    }
                }
            }
            else {
                if (cols > colsFrom) {
                    if (board.getBoard((rowsFrom / 8) - i, colsFrom + i) != '#') {
                        return 3;
                    }
                }
                else {
                    if (board.getBoard((rowsFrom / 8) - i, colsFrom - i) != '#') {
                        return 3;
                    }
                }
            }
        }
        if (board.getBoard((rows / 8) - 1, cols - 1) == '#') {
            if (abs((rows / 8) - (rowsFrom / 8)) == abs(cols - colsFrom)) {
                return 0;
            }
            else return 6;
        }
        else if (isupper(board.getBoard((rows / 8) - 1, cols - 1))) {
            if (abs((rows / 8) - (rowsFrom / 8)) == abs(cols - colsFrom)) {
                return 9;
            }
            else return 6;
        }
        else return 3;
    }
}

int Move::queenMove(std::string to, int player, Board board, int pieceCol, int pieceRow,int whichPlayer)
{
    int result = Move::turretMove(to, player, board, pieceCol, pieceRow, whichPlayer);
    if (result == 0 || result == 9) return result;
    result = Move::runnerMove(to, player, board, pieceCol, pieceRow, whichPlayer);
    return result;
}

int Move::kingMove(std::string to, int player, Board board, int pieceCol, int pieceRow,int whichPlayer)
{
    int rows = 8 * ((int)(to.at(3)) - 48);
    int rowsFrom = 8 * ((int)(to.at(1)) - 48);
    int cols = (int)(to.at(2)) - 96;
    int colsFrom = (int)(to.at(0)) - 96;

    if (whichPlayer != player) return 2;
    if (player == 0) {
        if ((rows == (pieceRow * 8) - 8 && cols == pieceCol - 1) || (rows == (pieceRow * 8) && cols == pieceCol - 1) || (rows == (pieceRow * 8) + 8 && cols == pieceCol - 1)
            || (rows == (pieceRow * 8) - 8 && cols == pieceCol) || (rows == (pieceRow * 8) - 8 && cols == pieceCol + 1) || (rows == (pieceRow * 8) && cols == pieceCol + 1)
            || (rows == (pieceRow * 8) + 8 && cols == pieceCol + 1) || (rows == (pieceRow * 8) + 8 && cols == pieceCol)) {
            if (board.getBoard((rows / 8) - 1, cols - 1) == '#') {
                return 0;
            }
            else if (islower(board.getBoard((rows / 8) - 1, cols - 1))) {
                return 9;
            }
            else return 3;
        }
        else return 6;
    }
    else {
        if ((rows == (pieceRow * 8) - 8 && cols == pieceCol - 1) || (rows == (pieceRow * 8) && cols == pieceCol - 1) || (rows == (pieceRow * 8) + 8 && cols == pieceCol - 1)
            || (rows == (pieceRow * 8) - 8 && cols == pieceCol) || (rows == (pieceRow * 8) - 8 && cols == pieceCol + 1) || (rows == (pieceRow * 8) && cols == pieceCol + 1)
            || (rows == (pieceRow * 8) + 8 && cols == pieceCol + 1) || (rows == (pieceRow * 8) + 8 && cols == pieceCol)) {
            if (board.getBoard((rows / 8) - 1, cols - 1) == '#') {
                return 0;
            }
            else if (isupper(board.getBoard((rows / 8) - 1, cols - 1))) {
                return 9;
            }
            else return 3;
        }
        else return 6;
    }
}

int Move::pionMove(std::string to, int player, Board board, int pieceCol, int pieceRow,int whichPlayer,bool isMoved)
{
    int rows = 8 * ((int)(to.at(3)) - 48);
    int rowsFrom = 8 * ((int)(to.at(1)) - 48);
    int cols = (int)(to.at(2)) - 96;
    int colsFrom = (int)(to.at(0)) - 96;

    if (board.getBoard((rowsFrom / 8) - 1, colsFrom - 1) == '#' || player != whichPlayer) return 2;
    if (player == 0) {
        if (rows <= rowsFrom) {
            return 6;
        }
        else if (cols != colsFrom) {
            if (cols == colsFrom + 1) {
                if (rows == rowsFrom + 8) {
                    if (islower(board.getBoard((rows / 8) - 1, cols - 1))) {
                        return 9;
                    }
                    else return 6;
                }
                return 6;
            }
            else if (cols == colsFrom - 1) {
                if (rows == rowsFrom + 8) {
                    if (islower(board.getBoard((rows / 8) - 1, cols - 1))) {
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
            if (isMoved) return 6;
            if (board.getBoard((rows / 8) - 1, cols - 1) == '#') {
                if (board.getBoard((rows / 8) - 2, cols - 1 == '#')) {
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
            if (board.getBoard((rows / 8) - 1, cols - 1) == '#') {
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
                    if (isupper(board.getBoard((rows / 8) - 1, cols - 1))) {
                        return 9;
                    }
                    else return 6;
                }
                return 6;
            }
            else if (cols == colsFrom - 1) {
                if (rows == rowsFrom - 8) {
                    if (isupper(board.getBoard((rows / 8) - 1, cols - 1))) {
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
            if (isMoved) return 6;
            if (board.getBoard((rows / 8) - 1, cols - 1) == '#') {
                if (board.getBoard((rows / 8), cols - 1 == '#')) {
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
            if (board.getBoard((rows / 8) - 1, cols - 1) == '#') {
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