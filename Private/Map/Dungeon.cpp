#include "Map/Dungeon.h"
#include "Characters/Player.h"
#include <iostream>
#include "Map/Room.h"
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
	for (int r = 0; r < rows; r++) {
		for (int c = 0; c < cols; c++) {
			if (r == player.getPlayerX() && c == player.getPlayerY()) {
				std::cout << " P ";
				visited[r][c] = true;
			}
			else if (visited[r][c] == true) {
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

void Dungeon::trackPlayerPosition()
{

}
