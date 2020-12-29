#include "Manager.h"

Manager::Manager(int whichPlayer,Player* p1,Player* p2)
{
	setPlayer(whichPlayer);
	createPlayers(p1,p2);
}

Manager::~Manager()
{
	this->_players.clear();
}

int Manager::whichPlayer() const
{
	return this->_whichPlayer;
}

void Manager::setPlayer(int whichPlayer)
{
	this->_whichPlayer = whichPlayer;
}

void Manager::createPlayers(Player* p1,Player* p2)
{
	this->_players.push_back(p1);
	this->_players.push_back(p2);
}
