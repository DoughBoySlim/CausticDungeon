#include "Characters/Enemy/Orc.h"
#include "Characters/Enemy/Enemy.h"

Orc::Orc() : Enemy(30.f, 15.f, 8.f, "Orc") {}

void Orc::attack(BaseCharacter& target) {
	std::cout << "The orc attacks the player!\n";
	std::cout << "This deals " << getAttackDamage() << " damage\n";

	target.takeDamage(getAttackDamage());

	std::cout << target.getName() << " has " << target.getHealthPoints() << " remaining!\n";
}

void Orc::die(BaseCharacter& character)
{
	// Treasure Implementation
}