#include "Map/Room.h"
#include "cstdlib"
#include <iostream>


Room::Room(RoomType type)
{
	roomType = type;
}

Room::RoomType Room::getRoomType()
{
	return roomType;
}

void Room::printRoomType(RoomType roomType)
{
	if (roomType == RoomType::Enemy) {
		std::cout << " E ";
	}
	else if (roomType == RoomType::Treasure) {
		std::cout << " T ";
	}
	else if (roomType == RoomType::Rest) {
		std::cout << " R ";
	}
	else if (roomType == RoomType::Exit) {
		std::cout << " L ";
	}
}


