#include <iostream>
#include "Array.h"

//copy values from one array to another
static void copy(const Array& original, Array& destination)
{
	for (int i = 0; i < original.m_size; ++i)
	{
		original.m_buffer[i] = destination.m_buffer[i];
	}
}

//check if array is full
static bool isFull(Array& original)
{
	return original.m_size == original.m_maxCapacity;
}

//check if array is empty
static bool isEmpty(Array& original)
{
	return original.m_size == 0;
}

//check if array is empty to a capacityFactor
static bool isEmptyToFactor(Array& original)
{
	return original.m_size <= (original.m_maxCapacity / original.m_capacityFactor);
}

//increase array max capacity by scale factor
static int increaseMaxCapacity(Array& original)
{
	original.m_maxCapacity = (original.m_size <= 0) ? (1 + original.m_maxCapacity) * original.m_capacityFactor : original.m_maxCapacity * original.m_capacityFactor;
	return original.m_maxCapacity;
}

//decrease array max capacity by scale factor
static int decreaseMaxCapacity(Array& original)
{
	original.m_maxCapacity = (original.m_size <= 0) ? 0 : original.m_maxCapacity / original.m_capacityFactor;
	return original.m_maxCapacity;
}

//constructor default
Array::Array()
{
	m_size = 0;
	m_maxCapacity = m_size;
	m_buffer = nullptr;
}

//constructor with capacity arg
Array::Array(int capacity)
{
	m_size = 0;
	m_maxCapacity = capacity;
	m_buffer = new int[m_maxCapacity];
}

//constructor copy
Array::Array(const Array& other)
{
	m_size = other.m_size;
	m_maxCapacity = other.m_maxCapacity;
	m_buffer = new int[m_maxCapacity];
	if (m_size > 0)
	{
		copy(other, *this);
	}
}

//destructor
Array::~Array()
{
	if (m_buffer != nullptr)
	{
		delete m_buffer;
		m_buffer = nullptr;
	}
	m_size = -1;
}

//adding an element to arrays last element
//something is wrong with isFull branch. value assigning is not working if using after isFull branch, but works normaly if isFull branch was not initialized.
void Array::push(int value)
{
	if (isFull(*this))
	{
		m_maxCapacity = increaseMaxCapacity(*this);
		Array newArray(*this);
		delete m_buffer;
		m_buffer = new int[m_maxCapacity];
		copy(newArray, *this);
	}
	m_buffer[m_size++] = value;
}

//function for printing
void Array::print() const
//std::ostream& operator<<(std::ostream& os, Array& array)
{
	for (int i = 0; i < m_size; ++i)
	{
		std::cout << m_buffer[i] << std::endl;
	}
}




