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

    Type fetch() { return this->m_buffer[this->m_size]; }
    int getSize() const { return this->m_size; }
    int getMaxCapacity() const { return this->m_maxCapacity; }
    Type getAtIndex(int destinationIndex) const
    {
        return this->getElement(destinationIndex);
    }

    void print() const;
};

#endif // STACK_H

template<typename Type>
void Stack<Type>::print() const
{
    for (int i = 0; i < this->m_size; ++i)
    {
        std::cout << this->m_buffer[i] << std::endl;
    }
}

template<typename Type>
void Array<Type>::print() const
{
    for (int i = 0; i < this->m_size; ++i)
    {
        std::cout << this->m_buffer[i] << std::endl;
    }
}