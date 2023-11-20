#include "Array.h"

int main(int argc, char** argv)
{

	Array a1;
	Array a2(5);

	for (int i = 0; i < 5; ++i)
	{
		a1.push(i);
	}

	for (int i = 10; i < 14; ++i)
	{
		a2.push(i);
	}

	a1.print();
	a2.print();

	return 0;
}