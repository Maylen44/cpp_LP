#ifndef ARRAY_H
#define ARRAY_H
#include <iostream>

const int CAPACITY_FACTOR = 2;

template<typename Type>

class Array
{
public:
	//constructor default
	Array()
	{
		m_size = 0;
		m_maxCapacity = m_size;
		m_buffer = nullptr;
	}

	//constructor with capacity arg
	Array(Type capacity)
	{
		m_size = 0;
		capacity = (capacity < 0) ? -capacity : capacity;
		m_maxCapacity = capacity;
		m_buffer = new Type[m_maxCapacity];
	}

	//constructor copy
	Array(const Array& origin)
	{
		m_size = origin.m_size;
		m_maxCapacity = origin.m_maxCapacity;
		m_buffer = new Type[m_maxCapacity];
		if (m_size > 0)
		{
			copyFrom(origin);
		}
	}

	//destructor
	~Array()
	{
		if (m_buffer != nullptr)
		{
			delete m_buffer;
			m_buffer = nullptr;
		}
		m_size = -1;
	}

	//adding an element to arrays last element
	void push(Type value)
	{
		if (m_size == m_maxCapacity)
		{
			increaseMaxCapacity();

			Array newArray(*this);
			delete m_buffer;
			m_buffer = new Type[m_maxCapacity];
			if (m_size > 0)
			{
				copyFrom(newArray);
			}
		}
		m_buffer[m_size++] = value;
	}

	//removing arrays last element
	void pop()
	{
		m_size = (m_size > 0) ? --m_size : 0;
		if (m_size <= (m_maxCapacity / CAPACITY_FACTOR) && m_size != 0)
		{
			decreaseMaxCapacity();
			Array newArray(*this);
			delete m_buffer;
			m_buffer = new Type[m_maxCapacity];
			copyFrom(newArray);
		}
	}

	
	void print() const;
	int getSize() const { return m_size; }

private:
	//copy array elements to another array
	void copyFrom(const Array& origin)
	{
		for (int i = 0; i < m_size; ++i)
		{
			m_buffer[i] = origin.m_buffer[i];
		}
	}

	//increase array max capacity by scale factor
	void increaseMaxCapacity()
	{
		m_maxCapacity = (m_size == 0) ? (1 + m_maxCapacity) * CAPACITY_FACTOR : m_maxCapacity * CAPACITY_FACTOR;
	}

	//decrease array max capacity by scale factor
	void decreaseMaxCapacity()
	{
		m_maxCapacity = (m_size == 0) ? 0 : m_maxCapacity / CAPACITY_FACTOR;
	}

	int m_size;
	int m_maxCapacity;
	Type* m_buffer;
};


#endif //ARRAY_H

template<typename Type>
void Array<Type>::print() const
{
	for (int i = 0; i < m_size; ++i)
	{
		std::cout << m_buffer[i] << std::endl;
	}
}

/*//function for printing
	void print() const
	{
		for (int i = 0; i < m_size; ++i)
		{
			std::cout << m_buffer[i] << std::endl;
		}
	}*/