#include <iostream>
#include "Character.h"
#include "Weapons.h"
#include "Armor.h"


/*
Updating notes:

1) Move fightingRound to a dedicated file, something like "game processes" or "combat"
1.1) Use new file to store all combat based calculations and functions. Remove such from classes and let only dedicated functionality for the classes, 
something like interface of actions that class can or can't do: equip, attack, dispach, block etc. Cut calculations based in combat file
2) Move combate results from main in combat file
3) Redo the fighting process overall. Either based on manual "button click" or on "auto fight till someone dies". If on "button click" think about 1.user input 
2.action interface
4) For the IS hirarchie of weapons and armor the logic is there and is fine. But for EXTEND you should use subclasses to extend a functionality of your mainclass. 
That been sad, structure would look more like: interface Action -> mainclass Weapons/Armor -> subclasses.
4.1) With this EXTENTION is the next question for IMPLEMENTATION. If we will use an Interface to act with our Weapon and subclasses, we refrence a overall actions: 
equipable, swapable, dropable, distructable ets. And by the Weapons itself we refrence the actions that can be done with weapons only: attack, block, parry etc. 
Is it a second interface, but for subclasses? Yes. Do we still have a logic linking from Sword IS a Weapon, due to writing a realisation of Interface Functions in 
subclasses? Maybe.
4.2) So by using Interface "Actions" than to use mainclass Weapons as a Interface for "Weapon based Actions" and subclasses as a realization for this interface we 
are using IMPLEMENTATION. Problem is, that every time we create a Sword we also create the whole new class weapons and actions interface. First of all its to big, 
second of all it has incapsulated data of 2 main classes in it and is dependet on bouth classes. Better think about not using Inheretans than...
5) What is life cycle of main and subclasses? Weapon is more of a "Empty Slot" or a "Category" of a class. If "Empty Slot" than the lifecycle of Weapon musst be 
independent of a subclass. If otherwise, than it schould be dependent.
5.1) So by having main class Weapons and having a variable for pointer to a specific object of Sword we really need only one mainclass Weapons with one Interface 
for Actions and our Swords can be created and dismantlet independently. Now is the question how schould the realization look like?
5.2) Realizetion: Having a "Weaponbased Actions" realized in our subclasses we have a posibility to adjust there functions specificly. Otherwise we can fit a realization 
in our Weapon class an have our subclasses provide us just with specified information variables: damage, weapon class, weight etc. So we use subclasses as information 
holders and just feed our mainclass information on how it should act. For instans, having bool isRanged can help adressing if mainclass uses a ranged or meele attack. 
Minus of this whole ordial is, that the whole realization is based in mainclass and its not good for EXTEND and IMPLEMENT mentality of inheritance. Plus is memory usage 
and lifecycles.
6) Do we need a virtualized inharitance with virtual distruction for mainclasses? If we stick for a theme:

	IActions           Player
Weapons	Armor
	///
	Objects

then not really. We have a Player class, that has his "Equipment Slots". In this equipment slots we populate with other classes via a IAction interface and use them. 
Our Objects just exist for the porpuse of providing information to equipt classes.
Now is a question how we interact with classes in Player? We sad, that IAction interface is main interface for all classes, so it cant have attack for example in it, 
because its not Weaponbased interface. Weapon class is not directly inhereted by Player class, so using virtualbased interface of Weapon is for Player not available.
Virtual inharitance is not needed, but a functionality of classes is needed in Player class. 
Oh. One more thing. We cant use IAction interface for Player, for obvious reasons, player is not equipable or such. So do i have a pointer to a interface as a Player 
class and use its functions so? If so, than by using this interface we can have a pointer to a weapon itself if Player, fetched for us via IAction interface and than 
use Weapons interface to use its interface

7) How many classes do i need in total befor the runtime? Players can be so many as wished. IActions and other interfaces can be made just one time (question about 
overriding data here is not aplicable, because the realization is in other classes)
Weapons and Armor can be made just one time, but the problem acuers with overriding a data. Maybe use one new Weapon and Armor Class for each new Player? So each 
Player has its own class Weapons, that is dedicated to them (as a slot for a Weapon. Everyone has there on slots).
But now with each Player we have new Weapon and Armor classes, that each have new IAction interfaces for instance.
Specified object just exist, independent.

8) Association: Agrigation yes, in Weapons and Armor classes to specified objects. In Player class is the question. Weapon and Armor classes in Player are always there.  
There lifecycle ends with Player. For that use Composition maybe: in Player class create a m_weaponslot and m_armorslot that are Weapon and Armor classes, so that they 
live with Player.
For the interface by Weapons and Armor is clear: either Inheritance or Agrigation (i see Inheritance more goodlooking for Interface, but via Agrigation i will need only 
one Interface and not a bunch)
For Player i dont really think we need to use same interface as for Weapons in any way. If i have a Composed weapons and armor in Player itself, i have a weapon and armor 
interface to work with. And theoreticly i can use this Composed variables to acces a Agrigated Interface for Actions. I dont know if it work with Inheritance, will need 
to try


8) Casting: there is a need in static_cast -ings by objects (specific weapons and armor) to the classes Armor and Weapons. For that, memberfields schould be samyyyisch, and 
then static_cast a new object inside of a Weapon or Armor class.

9) Bonus thouts: 
Specified object can be categoriesed. Enum can be a fast way to do it
Clasifiing class objects as overarching class. Can be usefull for future extencions of classes, but for now just Actions Interface would do
My original thouts on making a diferent file for combat seems pointless, if magority of realization will be in classes. So maybe overthink an idea with class "Trigger/Event" instead or something like this.
Spliting Headers and CPP Files. Caus we dont work with templates right now, its maybe better to split the files.
Implement object (i refer to lesser classes) counters and overall just use more "global" variables, to save information about classes and not objects


*/

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