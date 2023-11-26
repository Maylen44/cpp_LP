#include <iostream>
#include "Array.h"
#include "Stack.h"

int main(int argc, char** argv)
{

	Stack<int> s1;
	Stack<int> s2(2);
	Stack<const char*> s4;

	Array<int> a1;

	for (int i = 0; i < 10; ++i)
	{
		a1.addElement(i);
	}

	s2.pushBack(77);
	s2.pushBack(66);
	s2.pushBack(55);

	Stack<int> s3(s2);

	
	s4.pushBack("Ich ");
	s4.pushBack("sitz ");
	s4.pushBack("schon ");
	s4.pushBack("wieder ");
	s4.pushBack("dicht ");
	s4.pushBack("in ");
	s4.pushBack("dem ");
	s4.pushBack("Flieger.");

	a1.print();
	s2.print();
	s4.print();

	std::cout << "POP" << std::endl;

	a1.removeElement();
	s2.popBack();
	s4.popBack();
	
	a1.print();
	s2.print();
	s4.print();

	std::cout << "POP" << std::endl;
	std::cout << "POP" << std::endl;

	std::cout << s4.fetch() << std::endl;
	std::cout << s4.getAtIndex(2) << std::endl;
	std::cout << s4.getMaxCapacity() << std::endl;
	std::cout << s4.getSize() << std::endl;

	/*
	Array<int> a1;
	Array<int> a2(5);
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

	std::cout << "POP" << std::endl;
	std::cout << "POP" << std::endl;


	a4.print();
	std::cout << "POP" << std::endl;
	a4.addElement("Element 1");
	a4.print();
	std::cout << "POP" << std::endl;
	a4.addElement("Element 2", 3);
	a4.print();
	std::cout << "POP" << std::endl;
	std::cout << "POP" << std::endl;
	a4.removeElement();
	a4.removeElement();
	a4.print();
	std::cout << "POP" << std::endl;
	a4.removeElement(1);
	a4.print();


	while (true)
	{
		Array<int> a5 = a2;
		a5 = a1;
		a5.print();

		Array<int> a6 = a1 + a2;
		a6.print();
	}*/

	return 0;
}