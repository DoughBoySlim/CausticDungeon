#include "GameLoop.h"
#include "Map/Dungeon.h"
#include "Map/Room.h"
#include "Characters/Enemy/Enemy.h"
#include "Characters/Player.h"
#include <iostream>

GameLoop::GameLoop(Dungeon& dungeonRef, Player& playerRef) : dungeonGrid(dungeonRef), player(playerRef) {}

void GameLoop::run()
{
	char input;
	char leave = ' ';
	char playLonger = 'Y';
	dungeonGrid.printDungeon(player);

	std::cout << "You found a baseball bat!\n";
	player.setWeaponType(Player::WeaponType::Bat);
	while (playLonger == 'Y' || playLonger == 'y') {


		std::cout << "Please Enter Your Movement (WASD)\n";

		std::cin >> input;
		dungeonGrid.printVisited();
		std::cout << "--------------------\n";
		player.movePlayer(input, dungeonGrid);
		switch (dungeonGrid.checkPlayerTile(player))
		{
		case Room::RoomType::Enemy:
			attackPhase();
			break;
		case Room::RoomType::Treasure:
			std::cout << "You are in a Treasure room!\n";
			break;
		case Room::RoomType::Rest:
			std::cout << "you entered a room you can rest in!\n";
			player.playerRests(dungeonGrid);
			break;
		case Room::RoomType::Exit:
			std::cout << "Do you want to leave? (Ends the Game)\n";
			std::cin >> leave;
			if (leave == 'y' || leave == 'Y') {
				printStats();
				return;
			}
			break;
		default:
			break;
		}
	
	}
	return;
}

void GameLoop::attackPhase()
{
	int x = player.getPlayerX();
	int y = player.getPlayerY();
	char input = ' ';
	float playerHealth = player.getHealthPoints();
	Room& room = dungeonGrid.getDungeonRoom(player);
	if (!room.getEnemyPtr()) {
		room.setEnemyPtr(Enemy::spawnEnemy());
	}
	Enemy* enemy = room.getEnemyPtr(); 
	if (enemy) {
		float enemyHealth = enemy->getHealthPoints();

		std::cout << "A " << enemy->getEnemyClass() << " appeared!\n";
		char choice = playerAttackChoice(input);
		while (playerHealth > 0 && enemyHealth > 0 && (choice == 'y' || choice == 'Y')) {
			std::cout << "COMBAT HAS BEGUN!\n";
			player.attack(*enemy);
			enemyHealth = enemy->getHealthPoints();
			std::cout << "The enemy has " << enemyHealth << " remaining!\n";
			if (enemy->getArmorPoints() == 0) {
				std::cout << "The enemies armor broke!\n";
			}
			else {
				std::cout << "The enemy still has armor on!\n";
			}
			enemy->attack(player);
			if (player.getArmorPoints() == 0) {
				std::cout << "You have no armor remaining!\n";
			}
			else {
				std::cout << "You have " << player.getArmorPoints() << " remaining!\n";
			}

			std::cout << "Do you want to keep attacking?\n";
			playerAttackChoice(choice);
		}
		if (choice != 'y' && choice != 'Y') {
			return;
		}
	}
}

char GameLoop::playerAttackChoice(char choice)
{
	std::cout << "Do you want to fight the enemy? (Y/N)" << '\n';
	std::cin >> choice;
	return choice;
}

void GameLoop::printStats()
{
	std::cout << "------ Game Over ------\n";
	std::cout << "---- " << player.getName() << "'s Stats----\n";
	std::cout << "---- " << player.getTreasure() << " treasure gained!\n";
}



