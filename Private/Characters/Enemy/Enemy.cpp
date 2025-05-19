#include "Characters/Enemy/Enemy.h"
#include "Characters/Enemy/Goblin.h"
#include "Characters/Enemy/Orc.h"
#include "Characters/Enemy/Prisoner.h"
#include "Characters/Player.h"
#include <memory>
#include <cstdlib>

Enemy::Enemy(float health, float damage, float armor, const std::string& name)
	: BaseCharacter(health, damage, armor, name){}

std::unique_ptr<Enemy> Enemy::spawnEnemy()
{
	EnemyType enemyType = static_cast<EnemyType>(std::rand() % 3);
	switch (enemyType)
	{
	case EnemyType::Goblin:
		std::cout << "A Goblin was spawned\n";
		return std::make_unique<Goblin>();
	case EnemyType::Orc:
		std::cout << "An Orc was spawned\n";
		return std::make_unique<Orc>();
	case EnemyType::Prisoner:
		std::cout << "A Prisoner was spawned\n";
		return std::make_unique<Prisoner>();
	default:
		std::cout << "No Enemy Was Spawned!\n";
		return nullptr;
	}
}



