#pragma once
#include "Enemy.h"
class Prisoner : public Enemy
{
public:

	Prisoner();

	void attack(BaseCharacter& target) override;
	void die(BaseCharacter& character) override;
};

