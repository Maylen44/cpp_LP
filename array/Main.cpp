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
		a1.push(i);
	}

	for (int i = 10; i < 18; ++i)
	{
		a2.push(i);
	}

	for (int i = 66; i < 72; ++i)
	{
		a3.push(i);
	}

	a4.push("Ich ");
	a4.push("sitz ");
	a4.push("schon ");
	a4.push("wieder ");
	a4.push("dicht ");
	a4.push("in ");
	a4.push("dem ");
	a4.push("Flieger.");

	a1.print();
	a2.print();
	a3.print();
	a4.print();

	


	std::cout << "POP" << std::endl;

	for(int i = 0; i < 4; ++i)
	{
		a1.pop();
	}

	for (int i = 0; i < 2; ++i)
	{
		a2.pop();
	}

	for (int i = 0; i < 5; ++i)
	{
		a3.pop();
	}

	for (int i = 0; i < 3; ++i)
	{
		a4.pop();
	}

	a1.print();
	a2.print();
	a3.print();
	a4.print();
	
	
	while (true)
	{
		Array<int> a5 = a2;
		a5 = a1;
	}
	

	return 0;
}