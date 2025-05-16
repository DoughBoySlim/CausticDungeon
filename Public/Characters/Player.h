#pragma once
#include "Characters/BaseCharacter.h"
#include <vector>

class Dungeon;

class Player : public BaseCharacter
{

private:
	int y = 0;
	int x = 0;
	bool previouslyMoved = false;
	int treasure = 0;
	std::vector<std::vector<bool>> rested;


public:

	Player(std::string name);
	
	void movePlayer(char input, Dungeon& dungeon);
	void pickUpWeapon(std::string weaponType);
	void playerRests(Dungeon& dungeon);
	bool didPlayerRest();
	void die(BaseCharacter& character) override;

	int getPlayerX();
	int getPlayerY();

	std::vector<std::vector<bool>> getRested();
	void setRested(int playerX, int playerY);

};

