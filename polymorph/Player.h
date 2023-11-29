#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
#include "Weapons.h"
#include "Armor.h"

class Player
{
public:
	Player()
		: m_weapon(nullptr)
		, m_armor(nullptr)
		, m_hp(100)
		, m_id(++m_idCount)
	{
		std::cout << "New player Nr " << m_id << " was created." << std::endl;
	}

	void attack(Player* target)
	{
		std::cout << "Player " << m_id << " tryes to attack Player " << target->m_id << std::endl;
		if (target->m_hp > 0 && m_weapon != nullptr)
		{
			std::cout << "Players weapon ";
			m_weapon->attack();
			if (target->m_armor != nullptr)
			{
				target->m_armor->negate();
				int receavedDamage = target->m_armor->getDamageNegation() - m_weapon->getDamage();
				if (receavedDamage > 0)
				{
					receavedDamage = 0;
				}
				target->m_hp = target->m_hp + receavedDamage;
			}
			else
			{
				std::cout << "Player " << target->m_id << " doesn't have armor." << std::endl;
				std::cout << "Player " << target->m_id << " reseaves double Damage." << std::endl;
				target->m_hp = target->m_hp - (m_weapon->getDamage() * 2);
			}

			if (target->m_hp > 0)
			{
				std::cout << "Player " << target->m_id << " has " << target->m_hp << " HP left." << std::endl;
			}
			else
			{
				std::cout << "Player " << target->m_id << " dies." << std::endl;
			}
		}
		else if (m_weapon == nullptr)
		{
			std::cout << "Player " << m_id << " tryes to attack Player " << target->m_id << " without a weapon." << std::endl;
			std::cout << "Player " << m_id << " reseaves 5 Damage, for such a bad idea." << std::endl;
			m_hp -= 5;
			std::cout << "Player " << m_id << " has " << m_hp << " HP left." << std::endl;

		}
		else
		{
			std::cout << "Invalid target. Choise something else." << std::endl;
		}
	}

	void setWeapon(Weapon* weapon)
	{
		m_weapon = weapon;
	}

	void setArmor(Armor* armor)
	{
		m_armor = armor;
	}

	int getHP() const { return m_hp; }
	int getID() const { return m_id; }


private:
	Weapon* m_weapon;
	Armor* m_armor;
	int m_hp;
	int m_id;

	static int m_idCount;
};

int Player::m_idCount = 0;

#endif // PLAYER_H