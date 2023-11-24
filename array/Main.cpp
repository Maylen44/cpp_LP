#include <iostream>
#include "Array.h"

int main(int argc, char** argv)
{
	Array<int> a1;
	Array<int> a2(-5);
	Array<int> a3(a1);
	Array<const char*> a4;

	for (int i = 0; i < 10; ++i)
	{
		a1.addElement(i);
	}

	for (int i = 10; i < 18; ++i)
	{
		a2.addElement(i);
	}

	for (int i = 66; i < 72; ++i)
	{
		a3.addElement(i);
	}

	a4.addElement("Ich ");
	a4.addElement("sitz ");
	a4.addElement("schon ");
	a4.addElement("wieder ");
	a4.addElement("dicht ");
	a4.addElement("in ");
	a4.addElement("dem ");
	a4.addElement("Flieger.");


	a1.print();
	a2.print();
	a3.print();
	a4.print();

	a4.addElement("JaJaJa", 2);

	Array<int> a5 = a1 + a2;

	std::cout << "POP" << std::endl;

	for(int i = 0; i < 4; ++i)
	{
		a1.removeElement();
	}

	for (int i = 0; i < 2; ++i)
	{
		a2.removeElement();
	}

	for (int i = 0; i < 5; ++i)
	{
		a3.removeElement();
	}

	for (int i = 0; i < 3; ++i)
	{
		a4.removeElement();
	}

	a4.removeElement(5);

	a1.print();
	a2.print();
	a3.print();
	a4.print();
	a5.print();

	/*while (true)
	{
		Array<int> a5 = a2;
		a5 = a1;
		

		Array<int> a6 = a1 + a2;
		a6.print();

		
	}*/

	return 0;
}