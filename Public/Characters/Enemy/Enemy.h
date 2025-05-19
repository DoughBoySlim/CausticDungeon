#pragma once
#include "Characters/BaseCharacter.h"

class Player;

class Enemy : public BaseCharacter
{
public:

	Enemy(float health, float damage, float armor, const std::string& name);

	std::string getEnemyClass();
	
	enum class EnemyType {
		Goblin,
		Orc,
		Prisoner
	};

	static std::unique_ptr<Enemy> spawnEnemy();
	static std::string enemyClass;
};

