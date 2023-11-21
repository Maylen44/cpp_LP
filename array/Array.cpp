#include <iostream>
#include "Array.h"

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
	capacity = (capacity < 0) ? -capacity : capacity;
	m_maxCapacity = capacity;
	m_buffer = new int[m_maxCapacity];
}

//constructor copy
Array::Array(const Array& origin)
{
	m_size = origin.m_size;
	m_maxCapacity = origin.m_maxCapacity;
	m_buffer = new int[m_maxCapacity];
	if (m_size > 0)
	{
		copyFrom(origin);
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
void Array::push(int value)
{
	if (m_size == m_maxCapacity)
	{
		increaseMaxCapacity();
		Array newArray(*this);
		delete m_buffer;
		m_buffer = new int[m_maxCapacity];
		if (m_size > 0)
		{
			copyFrom(newArray);
		}
	}
	m_buffer[m_size++] = value;
}

//removing arrays last element
void Array::pop()
{
	m_size = (m_size > 0) ? --m_size : 0;
	if (m_size <= (m_maxCapacity / CAPACITY_FACTOR) && m_size != 0)
	{
		decreaseMaxCapacity();
		Array newArray(*this);
		delete m_buffer;
		m_buffer = new int[m_maxCapacity];
		copyFrom(newArray);
	}
}

//function for printing
void Array::print() const
{
	for (int i = 0; i < m_size; ++i)
	{
		std::cout << m_buffer[i] << std::endl;
	}
}

//copy array elements to another array
void Array::copyFrom(const Array& origin)
{
	for (int i = 0; i < m_size; ++i)
	{
		m_buffer[i] = origin.m_buffer[i];
		//origin = destination
	}
}

//increase array max capacity by scale factor
void Array::increaseMaxCapacity()
{
	m_maxCapacity = (m_size == 0) ? (1 + m_maxCapacity) * CAPACITY_FACTOR : m_maxCapacity * CAPACITY_FACTOR;
}

//decrease array max capacity by scale factor
void Array::decreaseMaxCapacity()
{
	m_maxCapacity = (m_size == 0) ? 0 : m_maxCapacity / CAPACITY_FACTOR;
}
