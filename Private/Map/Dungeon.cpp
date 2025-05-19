#include "Map/Dungeon.h"
#include "Characters/Player.h"
#include <iostream>
#include "Map/Room.h"
#include "Characters/Enemy/Enemy.h"
#include <ctime>

Dungeon::Dungeon()
{	
	dungeon.resize(rows, std::vector<Room>(cols));
	visited.resize(rows, std::vector<bool>(cols, false));
	for (int r = 0; r < rows; r++) {
		for (int c = 0; c < cols; c++) {
			if (r == 0 && c == 0) {
				dungeon[r][c] = Room::RoomType::Rest;
			}
			else if (isExitSpawned) {
				dungeon[r][c] = Room(static_cast<Room::RoomType>(std::rand() % 3));
			}
			else {
				dungeon[r][c] = Room(static_cast<Room::RoomType>(std::rand() % 4));
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

void Dungeon::checkPlayerTile(Player& player)
{
	int x = player.getPlayerX();
	int y = player.getPlayerY();
	Room& room = dungeon[x][y];

	Room::RoomType roomType = dungeon[x][y].getRoomType();
	switch (roomType)
	{
	case Room::Enemy:
		if (visited[x][y] == 1) return;
		room.setEnemyPtr(Enemy::spawnEnemy());
		Enemy* enemy = room.getEnemyPtr();
		if (enemy) {
			enemy->attack(player);
		}
		break;
	case Room::Treasure:
		// Tresure Logic
		std::cout << "You are in a treasure room\n";
		break;
	case Room::Rest:
		std::cout << "You entered a room you can rest in!\n";
		player.playerRests(*this);
		break;
	case Room::Exit:
		// Exit Logic
		std::cout << "You are in the exit room\n";
		break;
	default:
		break;
	}
	setVisited(x, y);
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

