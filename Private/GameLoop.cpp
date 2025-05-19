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
	char playLonger = 'Y';
	dungeonGrid.printDungeon(player);

	while (playLonger == 'Y' || playLonger == 'y') {

		std::cout << "Please Enter Your Movement (WASD)\n";

		std::cin >> input;
		dungeonGrid.printVisited();
		std::cout << "--------------------\n";
		player.movePlayer(input, dungeonGrid);
		dungeonGrid.checkPlayerTile(player);
		
		std::cout << "Do you want to keep playing? (Y/N)\n";
		std::cin >> playLonger;
	
	}
	return;
}

void GameLoop::attackPhase()
{
	int x = player.getPlayerX();
	int y = player.getPlayerY();
	float playerHealth = player.getHealthPoints();
	Room& room = dungeonGrid.getDungeonRoom(player);
	Enemy* enemy = room.getEnemyPtr();
	if (enemy) {
		float enemyHealth = enemy->getHealthPoints();

		while (playerHealth > 0 && enemyHealth > 0) {
			player.attack();
		}

	}
}


