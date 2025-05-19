#include "Characters/Player.h"
#include <iostream>
#include "Map/Dungeon.h"

Player::Player(std::string name) : BaseCharacter(100.f, 0.f, 0.f, name) 
{
	// hardcoded for 5 right now
	// Need to change in future
	// Would require passing in the instance of dungeon
	rested.resize(5, std::vector<bool>(5, false));
}

void Player::attack(BaseCharacter& target) {
	std::cout << "You swing your " << getWeaponType() << " at the enemy!\n";
	target.takeDamage(getAttackDamage());
}


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
		system("cls");
		dungeon.printDungeon(*this);
	}

}

void Player::pickUpWeapon()
{
	switch (weaponType)
	{
	case Player::WeaponType::Sword:
		std::cout << "You pick up a great sword!\n";
		setAttackDamage(20.f);
		break;
	case Player::WeaponType::Axe:
		std::cout << "You pick up a mighty axe!\n";
		setAttackDamage(10.f);
		break;
	case Player::WeaponType::Bat:
		std::cout << "You found a wooden bat!\n";
		setAttackDamage(5.f);
		break;
	default:
		break;
	}
}

void Player::playerRests(Dungeon& dungeon)
{
	if (dungeon.getVisited()[x][y] && rested[x][y]) {
		std::cout << "You already rested in this room!" << '\n';
		return;
	}
	char wantsToRest = ' ';
	if (getHealthPoints() == getMaxHealth()) {
		std::cout << "You can not rest right now though because you are already at Max Health!\n";
		return;
	}
	std::cout << "Would you like to rest in this room regaining health? (Y/N)\n";
	std::cin >> wantsToRest;
	if (wantsToRest == 'Y' || wantsToRest == 'y') {
		setHealthPoints(std::min(getHealthPoints() + 20.f, getMaxHealth()));
		std::cout << "The player rests regaining health!\n";
		rested[x][y] = true;
	}
	else {
		std::cout << "You decide not to rest!\n";
		rested[x][y] = false;
	}
}

bool Player::didPlayerRest()
{
	return false;
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

int Player::getTreasure()
{
	return treasure;
}

void Player::setWeaponType(WeaponType weapontype)
{
	weaponType = weapontype;
}

std::string Player::getWeaponType()
{
	switch (weaponType)
	{
	case Player::WeaponType::Sword:
		return "sword";
	case Player::WeaponType::Axe:
		return "axe";
	case Player::WeaponType::Bat:
		return "bat";
	default:
		return "bat";
		break;
	}
}

std::vector<std::vector<bool>> Player::getRested()
{
	return rested;
}

void Player::setRested(int playerX, int playerY)
{
	rested[playerX][playerY] = true;
}
