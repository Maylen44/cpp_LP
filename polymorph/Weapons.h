#ifndef WEAPONS_H
#define WEAPONS_H
#include <iostream>

class Weapon
{
public:
	Weapon(int damage) : m_damage(damage) {}

	virtual void attack()
	{
		std::cout << "does " << m_damage << " damage" << std::endl;
	}

	int getDamage() const {	return m_damage; }

private:
	int m_damage;
};

class Sword : public Weapon
{
public:
	Sword() : Weapon(10) {}

	void attack()
	{
		std::cout << "Sword ";
		Weapon::attack();
	}
};

class Knife : public Weapon
{
public:
	Knife() : Weapon(5) {}
	
	void attack()
	{
		std::cout << "Knife ";
		Weapon::attack();
	}
};

class Axe : public Weapon
{
public:
	Axe() : Weapon(15) {}

	void attack()
	{
		std::cout << "Axe ";
		Weapon::attack();
	}
};

#endif // WEAPONS_H