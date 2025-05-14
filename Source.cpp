#include <iostream>
#include "Dungeon.h"
#include <ctime>

int main() {
	std::srand(static_cast<unsigned>(std::time(0)));
	Dungeon dungeon;
	dungeon.printDungeon();
}