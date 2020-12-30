#pragma once
#include <iostream>
#include "Piece.h"
class Piece;
class Move
{
public:
	static int turretMove(std::string to,int player,Board& board,int pieceCol,int pieceRow,int whichPlayer,bool isCheckChess);
	static int horsemanMove(std::string to,int player,Board& board,int pieceCol,int pieceRow,int whichPlayer,bool isCheckChess);
	static int runnerMove(std::string to,int player,Board& board,int pieceCol,int pieceRow,int whichPlayer,bool isCheckChess);
	static int queenMove(std::string to,int player,Board& board,int pieceCol,int pieceRow,int whichPlayer,bool isCheckChess);
	static int kingMove(std::string to,int player,Board& board,int pieceCol,int pieceRow,int whichPlayer,bool isCheckChess);
	static int pionMove(std::string to,int player,Board& board,int pieceCol,int pieceRow,int whichPlayer,bool isMoved,bool isCheckChess);
	static int checkCheck(const Piece& piece, std::string kingSquare,int player,Board& board,int whichPLayer);
};