#pragma once
#include <iostream>
#include "Board.h"
class Move
{
public:
	static int turretMove(std::string to,int player,Board board,int pieceCol,int pieceRow,int whichPlayer);
	static int horsemanMove(std::string to,int player,Board board,int pieceCol,int pieceRow,int whichPlayer);
	static int runnerMove(std::string to,int player,Board board,int pieceCol,int pieceRow,int whichPlayer);
	static int queenMove(std::string to,int player,Board board,int pieceCol,int pieceRow,int whichPlayer);
	static int kingMove(std::string to,int player,Board board,int pieceCol,int pieceRow,int whichPlayer);
	static int pionMove(std::string to,int player,Board board,int pieceCol,int pieceRow,int whichPlayer,bool isMoved);
};