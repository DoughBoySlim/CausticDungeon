#pragma once
#include "cstdlib"
#include <vector>

class Enemy;

class Room
{
public:

	enum RoomType {
		Enemy,
		Treasure,
		Rest,
		Exit
	};
	Room(RoomType type = static_cast<RoomType>(std::rand() % 3));
	RoomType getRoomType();

	static void printRoomType(RoomType roomType);

private:

	RoomType roomType;

};

