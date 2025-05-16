#pragma once
#include "Characters/Enemy/Enemy.h"

class Goblin : public Enemy
{
public:

	Goblin();

	void attack(BaseCharacter& target) override;
	void die(BaseCharacter& character) override;
	void spawn();
};

