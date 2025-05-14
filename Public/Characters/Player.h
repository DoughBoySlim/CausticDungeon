#pragma once
#include "Characters/BaseCharacter.h"

class Dungeon;

class Player : public BaseCharacter
{

private:
	int y = 0;
	int x = 0;
	bool previouslyMoved = false;
	int treasure = 0;


public:

	Player(std::string name);
	
	void movePlayer(char input, Dungeon& dungeon);
	void pickUpWeapon(std::string weaponType);
	void playerRests(Dungeon& dungeon);
	void die(BaseCharacter& character) override;

	int getPlayerX();
	int getPlayerY();

};

