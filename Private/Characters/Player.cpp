#include "Characters/Player.h"
#include <iostream>
#include "Map/Dungeon.h"

Player::Player(std::string name) : BaseCharacter(100.f, 0.f, 0.f, name) { }


void Player::movePlayer(char input, Dungeon& dungeon)
{
	bool moved = false;
	switch (input)
	{
	case 'W':
	case 'w':
		if (x - 1 < 0)
			std::cout << "Invalid Move! You can't go out of Bounds\n";
		else {
			x--;
			moved = true;
		}
		break;
	case 'S':
	case 's':
		if (x + 1 >= 5)
			std::cout << "Invalid Move! You can't go out of Bounds\n";
		else {
			x++;
			moved = true;
		}
		break;
	case 'A':
	case 'a':
		if (y - 1 < 0)
			std::cout << "Invalid Move! You can't go out of Bounds\n";
		else {
			y--;
			moved = true;
		}
		break;
	case 'D':
	case 'd':
		if (y + 1 >= 5)
			std::cout << "Invalid Move! You can't go out of Bounds\n";
		else {
			y++;
			moved = true;
		}
		break;
	default:
		std::cout << "Invalid Input!\n";
		break;
	}

	if (moved) {
		dungeon.setVisited(x, y);
		system("cls");
		dungeon.printDungeon(*this);
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

void Player::die(BaseCharacter& character) {
	std::cout << "You Died! Game Over!\n";
	// Insert Stats here
	// Such as Enemies killed
	// Treasure gained
}

int Player::getPlayerX()
{
	return x;
}

int Player::getPlayerY()
{
	return y;
}
