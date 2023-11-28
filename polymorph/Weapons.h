#ifndef WEAPONS_H
#define WEAPONS_H
#include <iostream>
#include "Player.h"

class Weapons : private Player
{
public:


private:
	int m_damage;
};

class Sword : private Weapons
{
public:


private:
	int m_damage;
};

class Knife : private Weapons
{
public:


private:
	int m_damage;
};

class Axe : private Weapons
{
public:


private:
	int m_damage;
};

#endif // WEAPONS_H