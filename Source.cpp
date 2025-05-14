#include <iostream>
#include "Dungeon.h"
#include <ctime>
#include "Player.h"

int main() {
	std::srand(static_cast<unsigned>(std::time(0)));
	Dungeon dungeon;
	Player player1("Ethan");
	dungeon.printDungeon(player1);
	player1.movePlayer('D', dungeon, true);
	player1.movePlayer('D', dungeon, true);
	player1.movePlayer('D', dungeon, true);
	player1.movePlayer('S', dungeon, true);
	player1.movePlayer('S', dungeon, true);
	player1.movePlayer('S', dungeon, true);

}