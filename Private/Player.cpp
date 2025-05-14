#include "Player.h"
#include <iostream>
#include "Dungeon.h"

Player::Player(std::string name) : BaseCharacter(100.f, 0.f, 0.f, name) { }

void Player::movePlayer(char input, Dungeon& dungeon)
{
	switch (input)
	{
	case 'W':
	case 'w':
		if (x - 1 < 0)
			std::cout << "Invalid Move! You can't go out of Bounds\n";
		else {
			x--;
			dungeon.setVisited(x, y);
		}
		break;
	case 'S':
	case 's':
		if (x + 1 >= 5)
			std::cout << "Invalid Move! You can't go out of Bounds\n";
		else {
			x++;
			dungeon.setVisited(x, y);
		}
		dungeon.printDungeon(this);
		break;
	case 'A':
	case 'a':
		if (y - 1 < 0)
			std::cout << "Invalid Move! You can't go out of Bounds\n";
		else {
			y--;
			dungeon.setVisited(x, y);
		}
		break;
	case 'D':
	case 'd':
		if (y + 1 >= 5)
			std::cout << "Invalid Move! You can't go out of Bounds\n";
		else {
			y++;
			dungeon.setVisited(x, y);
		}
		break;
	default:
		std::cout << "Invalid Input!\n";
		break;
	}

}

void Player::pickUpWeapon(std::string weaponType)
{
	if (weaponType == "Sword") {
		setAttackDamage(20.f);
		std::cout << "You picked up a Sword!" << '\n';
	}
	else if (weaponType == "Bat") {
		setAttackDamage(5.f);
		std::cout << "You picked up a Bat!\n";
	}
	else if (weaponType == "Axe") {
		setAttackDamage(10.f);
		std::cout << "You picked up an Axe!\n";
	}
}

void Player::playerRests(Dungeon& dungeon)
{
	if (dungeon.getVisited()[x][y]) {
		std::cout << "You already rested in this room!" << '\n';
	}
	setHealthPoints(std::min(getHealthPoints() + 20.f, getMaxHealth()));
	std::cout << "The player rests regaining health" << '\n';

	dungeon.getVisited()[x][y] = true;
}

int Player::getPlayerX()
{
	return x;
}

int Player::getPlayerY()
{
	return y;
}
