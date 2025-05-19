#pragma once
#include "Characters/BaseCharacter.h"
#include <vector>

class Dungeon;
class Enemy;

class Player : public BaseCharacter
{

public:
	enum class WeaponType {
		Sword,
		Axe,
		Bat
	};

	Player(std::string name);

	void attack(BaseCharacter& target) override;
	
	void movePlayer(char input, Dungeon& dungeon);
	void pickUpWeapon();
	void playerRests(Dungeon& dungeon);
	bool didPlayerRest();
	void die(BaseCharacter& character) override;

	int getPlayerX();
	int getPlayerY();
	int getTreasure();

	void setWeaponType(WeaponType weapontype);
	std::string getWeaponType();

	std::vector<std::vector<bool>> getRested();
	void setRested(int playerX, int playerY);


private:
	int y = 0;
	int x = 0;
	bool previouslyMoved = false;
	int treasure = 0;
	std::vector<std::vector<bool>> rested;
	WeaponType weaponType = WeaponType::Bat;

};

