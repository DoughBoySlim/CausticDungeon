#pragma once
#include <string>
class BaseCharacter
{

private:
	
	float healthPoints;
	float maxHealth;
	float attackDamage;
	float armorPoints;
	std::string nameTag;

public:
	BaseCharacter();
	BaseCharacter(float health, float damage, float armor, const std::string& name);

	// Attacking
	void takeDamage(float damage);


	// Getters
	float getHealthPoints() const;
	float getMaxHealth() const;
	float getAttackDamage() const;
	float getArmorPoints() const;
	std::string getName() const;

	// Setters
	void setHealthPoints(float health);
	void setMaxHealth(float health);
	void setAttackDamage(float damage);
	void setArmorPoints(float armor);
	void setName(std::string name);
};

