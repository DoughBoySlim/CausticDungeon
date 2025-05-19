#include "Characters/Enemy/Goblin.h"



Goblin::Goblin() : Enemy(20.f, 10.f, 5.f, "Goblin") {}

void Goblin::attack(BaseCharacter& target) {
	std::cout << "The goblin attacks the player!\n";
	std::cout << "This deals " << getAttackDamage() << " damage\n";

	target.takeDamage(getAttackDamage());

	std::cout << target.getName() << " has " << target.getHealthPoints() << " remaining!\n";
}

void Goblin::die(BaseCharacter& character)
{
	// Treasure Implementation
}

