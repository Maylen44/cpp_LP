#ifndef STACK_H
#define STACK_H
#include <iostream>
#include "Array.h"

template<typename Type> class Stack : private Array<Type>
{
public:
    Stack(int capacity = 0) : Array<Type>(capacity) {}

    void pushBack(Type value)
    {
        this->addElement(value);
    }
    
    void popBack()
    {
        this->removeElement();
    }

    Type fetch() { return this->getElement(this->getSize()) ; }

    void print() const;
};

template<typename Type>
void Stack<Type>::print() const
{
    for (int i = 0; i < this->getSize(); ++i)
    {
        std::cout << this->getElement(i) << std::endl;
    }
}

#endif // STACK_H