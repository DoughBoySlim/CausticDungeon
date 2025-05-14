#pragma once
#include <vector>
#include "Room.h"
class Dungeon
{
private:

	std::vector<std::vector<Room>> dungeon;
	std::vector<std::vector<bool>> visited;
	int rows = 5;
	int cols = 5;
	bool isExitSpawned = false;

public:

	Dungeon();

	void printDungeon();
};

