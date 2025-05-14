#include <iostream>
#include "Map/Dungeon.h"
#include <ctime>
#include "Characters/Player.h"
#include "Gameloop.h"

int main() {
	std::srand(static_cast<unsigned>(std::time(0)));
	Dungeon dungeon;
	Player player("Ethan");

	GameLoop game(dungeon, player);

	game.run();
	return 0;
}