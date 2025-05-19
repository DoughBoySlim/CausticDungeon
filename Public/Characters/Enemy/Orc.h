#pragma once
#include "Enemy.h"
class Orc : public Enemy
{
public:

	Orc();

	void attack(BaseCharacter& target) override;
	void die(BaseCharacter& character) override;
};

