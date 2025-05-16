#include "Characters/BaseCharacter.h"
#include <algorithm>

BaseCharacter::BaseCharacter(float health, float damage, float armor, const std::string& name)
{
    healthPoints = health;
    maxHealth = health;
    attackDamage = damage;
    armorPoints = armor;
    nameTag = name;
}

void BaseCharacter::takeDamage(float damage)
{
    if (damage > 0.0f) {
        healthPoints = std::clamp(healthPoints - damage, 0.0f, maxHealth);
    }
}

void BaseCharacter::attack(BaseCharacter& target)
{
}

void BaseCharacter::die(BaseCharacter& character) {}

float BaseCharacter::getHealthPoints() const
{
    return healthPoints;
}

float BaseCharacter::getMaxHealth() const
{
    return maxHealth;
}

float BaseCharacter::getAttackDamage() const
{
    return attackDamage;
}

float BaseCharacter::getArmorPoints() const
{
    return armorPoints;
}

std::string BaseCharacter::getName() const
{
    return nameTag;
}

void BaseCharacter::setHealthPoints(float health)
{
    healthPoints = health;
}

void BaseCharacter::setMaxHealth(float health)
{
    maxHealth = health;
}

void BaseCharacter::setAttackDamage(float damage)
{
    attackDamage = damage;
}

void BaseCharacter::setArmorPoints(float armor)
{
    armor = armorPoints;
}

void BaseCharacter::setName(std::string name)
{
    nameTag = name;
}
