#pragma once
#include "cstdlib"
#include <vector>
#include <memory>
#include "Characters/Enemy/Enemy.h"

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

	Room(const Room&) = delete;
	Room& operator=(const Room&) = delete;

	Room(Room&&) noexcept = default;          
	Room& operator=(Room&&) noexcept = default;

	RoomType getRoomType() const;

	static void printRoomType(RoomType roomType);

	::Enemy* getEnemyPtr();

	void setEnemyPtr(std::unique_ptr<::Enemy> newEnemy);

private:

	RoomType roomType;
	std::unique_ptr<::Enemy> enemyPtr;
};

