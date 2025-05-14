#include "Characters/Goblin.h"

Goblin::Goblin() : BaseCharacter(20.f, 10.f, 5.f, "Goblin") {}

void Goblin::attack(BaseCharacter& target) {
	std::cout << "The goblin attacks the player!\n";
	std::cout << "This deals " << getAttackDamage() << "health\n";

	target.takeDamage(getAttackDamage());
}

void Goblin::die(BaseCharacter& character)
{
	// Treasure Implementation
}
