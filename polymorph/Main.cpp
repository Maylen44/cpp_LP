#include <iostream>
#include "Character.h"
#include "Weapons.h"
#include "Armor.h"

void fightingRound(Character* one, Character* two, int round)
{
	std::cout << std::endl;
	std::cout << "Start of the " << round << " Round!" << std::endl;

	if (one->getHP() > 0)
	{
		one->attack(two);
	}
	if (two->getHP() > 0)
	{
		two->attack(one);
	}

	std::cout << "Round " << round << " has ended!";
	std::cout << std::endl;
}

int main(int argc, char** argv)
{
	Sword a;
	Knife b;
	Axe c;

	LetherArmor l;
	Chainmail m;
	PlateArmor p;

	Character p1;
	Character p2;

	p1.setWeapon(&b);
	p2.setWeapon(&a);

	p1.setArmor(&l);
	p2.setArmor(&p);


	bool isFighting = true;
	int round = 1;
	while(isFighting == true)
	{
		fightingRound(&p1, &p2, round);
		++round;
		if (p1.getHP() <= 0 || p2.getHP() <= 0)
		{
			isFighting = false;
		}
	}

	if (p1.getHP() <= 0 && p2.getHP() <= 0)
	{
		std::cout << "Both players died in the turnament. How ironic." << std::endl;
	}
	else if (p1.getHP() <= 0)
	{
		std::cout << "Player " << p2.getID() << " succsesfully killed Player " << p1.getID() << "! Congrats." << std::endl;
	}
	else if (p2.getHP() <= 0)
	{
		std::cout << "Player " << p1.getID() << " succsesfully killed Player " << p2.getID() << "! Congrats." << std::endl;
	}

	return 0;
}