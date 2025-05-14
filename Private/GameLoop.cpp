#include "GameLoop.h"
#include "Dungeon.h";
#include "Player.h";
#include <iostream>

GameLoop::GameLoop(Dungeon& dungeonRef, Player& playerRef) : dungeon(dungeonRef), player(playerRef) {}

void GameLoop::run()
{
	char input;
	char playLonger = 'Y';
	dungeon.printDungeon(player);

	while (playLonger == 'Y' || playLonger == 'y') {

		std::cout << "Please Enter Your Movement (WASD)\n";

		std::cin >> input;
		player.movePlayer(input, dungeon);
		
		std::cout << "Do you want to keep playing? (Y/N)\n";
		std::cin >> playLonger;

	}
	return;
}
