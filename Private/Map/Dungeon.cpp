#include "Map/Dungeon.h"
#include "Characters/Player.h"
#include <iostream>
#include "Map/Room.h"
#include "Characters/Enemy/Enemy.h"
#include <ctime>

Dungeon::Dungeon()
{	
	dungeon.resize(rows);
	visited.resize(rows, std::vector<bool>(cols, false));
	for (int r = 0; r < rows; r++) {
		dungeon[r].reserve(cols);
		for (int c = 0; c < cols; c++) {
			if (r == 0 && c == 0) {
				dungeon[r].emplace_back(Room(Room::RoomType::Rest));
			}
			else if (isExitSpawned) {
				dungeon[r].emplace_back(Room(static_cast<Room::RoomType>(std::rand() % 3)));
			}
			else {
				dungeon[r].emplace_back(Room(static_cast<Room::RoomType>(std::rand() % 4)));
				if (dungeon[r][c].getRoomType() == Room::RoomType::Exit) {
					isExitSpawned = true;
				}
			}
		}
	}
}

void Dungeon::printDungeon(Player& player)
{
	setVisited(0, 0);
	for (int r = 0; r < rows; r++) {
		for (int c = 0; c < cols; c++) {
			if (r == player.getPlayerX() && c == player.getPlayerY()) {
				std::cout << " P ";
			}
			else if (visited[r][c]) {
				Room::printRoomType(dungeon[r][c].getRoomType());
			}
			else {
				std::cout << " . ";
			}
		}
		std::cout << '\n';
	}
}

std::vector<std::vector<bool>> Dungeon::getVisited()
{
	return visited;
}

void Dungeon::setVisited(int x, int y)
{
	visited[x][y] = true;
}

Room::RoomType Dungeon::checkPlayerTile(Player& player)
{
	int x = player.getPlayerX();
	int y = player.getPlayerY();
	setVisited(x, y);
	return dungeon[x][y].getRoomType();
}

Room& Dungeon::getDungeonRoom(Player& player)
{
	int x = player.getPlayerX();
	int y = player.getPlayerY();
	return dungeon[x][y];
}

void Dungeon::printVisited()
{
	for (int r = 0; r < 5; r++) {
		for (int c = 0; c < 5; c++) {
			std::cout << visited[r][c];
		}
		std::cout << '\n';
	}
}

