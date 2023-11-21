#include <iostream>
#include "Array.h"

int main(int argc, char** argv)
{

	Array a1;
	Array a2(-5);
	Array a3(a1);

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

	a1.print();
	a2.print();
	a3.print();

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

	a1.print();
	a2.print();
	a3.print();

	return 0;
}