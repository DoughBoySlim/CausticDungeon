#include "Characters/Enemy/Prisoner.h"
#include "Characters/Enemy/Enemy.h"

Prisoner::Prisoner() : Enemy(10.f, 5.f, 2.f, "Prisoner") {}

void Prisoner::attack(BaseCharacter& target) {
	std::cout << "The prisoner attacks the player!\n";
	std::cout << "This deals " << getAttackDamage() << " damage\n";

	target.takeDamage(getAttackDamage());

	std::cout << target.getName() << " has " << target.getHealthPoints() << " remaining!\n";
}

void Prisoner::die(BaseCharacter& character)
{
	// Treasure Implementation
}