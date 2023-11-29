#ifndef ARMOR_H
#define ARMOR_H
#include <iostream>

class Armor
{
public:
	Armor(int damageNegation) : m_damageNegation(damageNegation) {}

	virtual void negate()
	{
		std::cout << "negates " << m_damageNegation << " incoming damage." << std::endl;
	}

	int getDamageNegation() const
	{
		return m_damageNegation;
	}

private:
	int m_damageNegation;
};

class LetherArmor : public Armor
{
public:
	LetherArmor() : Armor(5) {}

	void negate()
	{
		std::cout << "Lether Armor ";
		Armor::negate();
	}
};

class Chainmail : public Armor
{
public:
	Chainmail() : Armor(10) {}

	void negate()
	{
		std::cout << "Chainmail ";
		Armor::negate();
	}
};

class PlateArmor : public Armor
{
public:
	PlateArmor() : Armor(15) {}

	void negate()
	{
		std::cout << "Plate Armor ";
		Armor::negate();
	}
};

#endif // ARMOR_H