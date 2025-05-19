#pragma once
#include <vector>
#include "Room.h"
class Player;

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

	Dungeon(const Dungeon&) = delete;
	Dungeon& operator=(const Dungeon&) = delete;

	Dungeon(Dungeon&&) noexcept = default;
	Dungeon& operator=(Dungeon&&) noexcept = default;


	void printDungeon(Player& player);
	std::vector<std::vector<bool>> getVisited();
	void setVisited(int x, int y);
	Room::RoomType checkPlayerTile(Player& player);

	Room& getDungeonRoom(Player& player);

	void printVisited();
};

