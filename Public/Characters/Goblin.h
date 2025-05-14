#pragma once
#include "Characters/BaseCharacter.h"

class Goblin : public BaseCharacter
{
public:

	Goblin();

	void attack(BaseCharacter& target) override;
	void die(BaseCharacter& character) override;
};

