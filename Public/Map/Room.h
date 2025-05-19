#pragma once
#include "cstdlib"
#include <vector>
#include <memory>

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

	::Enemy* getEnemyPtr();

	void setEnemyPtr(std::unique_ptr<::Enemy> newEnemy);

private:

	RoomType roomType;
	std::unique_ptr<::Enemy> enemyPtr;
};

