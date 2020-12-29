#pragma once
#include "Player.h"

class Manager
{
public:
	Manager(int whichPlayer,Player* p1,Player* p2);
	~Manager();
	int whichPlayer() const;
	void setPlayer(int whichPlayer);
	void createPlayers(Player* p1,Player* p2);
private:
	int _whichPlayer;
	std::vector<Player*> _players;
};