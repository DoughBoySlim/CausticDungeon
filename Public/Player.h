#pragma once
#include "BaseCharacter.h"

class Dungeon;

class Player : public BaseCharacter
{

private:
	int y = 0;
	int x = 0;


public:

	Player(std::string name);
	
	void movePlayer(char input, Dungeon& dungeon);
	void pickUpWeapon(std::string weaponType);
	void playerRests(Dungeon& dungeon);

	int getPlayerX();
	int getPlayerY();

};

