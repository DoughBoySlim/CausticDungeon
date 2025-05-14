#include "Dungeon.h"
#include <iostream>
#include "Room.h"
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

void Dungeon::printDungeon()
{
	for (int r = 0; r < rows; r++) {
		for (int c = 0; c < cols; c++) {
			if (visited[r][c] == false) {
				Room::printRoomType(dungeon[r][c].getRoomType());
			}
			else {
				std::cout << " . ";
			}
		}
		std::cout << '\n';
	}
}
