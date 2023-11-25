#ifndef ARRAY_H
#define ARRAY_H
#include <iostream>
#include <cassert>

const int CAPACITY_FACTOR = 2;

template<typename Type> class Array
{
public:
	//constructor default and with capacity arg
	Array(int capacity = 0)
	{
		assert(capacity >= 0 && "ERROR: Initializing a new array with negativ capacity.");

		m_size = 0;
		m_maxCapacity = capacity;
		if (m_maxCapacity > 0)
		{
			m_buffer = new Type[m_maxCapacity];
		}
	}

	//constructor copy
	Array(const Array& origin)
	{
		if (origin.m_maxCapacity > 0 && origin.m_size > 0)
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
		m_maxCapacity = -1;
	}

	//adding an element to arrays last element
	void addElement(Type value, int destinationIndex = -1)
	{
		if (m_size == m_maxCapacity)
		{
			resize(m_maxCapacity);
		}
		m_buffer[m_size++] = value;

		if(destinationIndex > -1 && destinationIndex < m_size)
		{
			int startIndex = m_size - 1;
			while (startIndex != destinationIndex)
			{
				swap(startIndex); //func shift(start index, how much to shift) ~ array concat
				--startIndex;
			}
		}
	}

	//removing arrays last element
	void removeElement(int destinationIndex = -1)
	{
		if (destinationIndex > -1 && destinationIndex < m_size)
		{
			int startIndex = destinationIndex;
			while (startIndex != m_size - 1)
			{
				swap(-startIndex);//shift
				++startIndex;
			}
		}
		m_size = (m_size > 0) ? --m_size : m_size;
		if (m_size <= (m_maxCapacity / CAPACITY_FACTOR) && m_size != 0)
		{
			resize(m_maxCapacity);
		}
	}

	//assign one array to another one by operator =
	Array operator=(const Array& origin)
	{
		if (origin.m_size > 0)
		{
			copyFrom(origin);
			return *this;
		}
	}

	//concatenate two arrays to another one by operator +
	Array operator+(const Array& rhs)
	{
		int newSize = m_size + rhs.m_size;
		Array<Type> newArray(newSize);
		if (newSize > 0)
		{
			newArray.copyFrom(*this, 0);
			newArray.copyFrom(rhs, m_size);
		}
		return newArray;
	}

	void print() const;
	int getSize() const { return m_size; }
	int getMaxCapacity() const { return m_maxCapacity; }
	Type getElement(int destinationIndex) const
	{
		assert(destinationIndex >= 0 && destinationIndex <= m_size - 1 && "ERROR: Trying to acces element on invalid index.");

		return m_buffer[destinationIndex];
	}

private:
	void copyFrom(const Array& origin, int startIndex = 0)
	{
		assert(startIndex <= m_size && startIndex >= 0 && "ERROR: Trying to copy an Array via boundaries invalid index.");

		int requiredCapacity = origin.m_size + startIndex;
		if (m_maxCapacity <= requiredCapacity)
		{
			resize(requiredCapacity);
		}
		for (int i = 0; i < origin.m_size; ++i)
		{
			m_buffer[startIndex] = origin.m_buffer[i];
			++startIndex;
			++m_size;
		}
	}

	void resize(int wantedSize)
	{
		if (m_size == wantedSize)
		{
			m_maxCapacity = (m_size == 0) ? (1 + m_maxCapacity) * CAPACITY_FACTOR : m_maxCapacity * CAPACITY_FACTOR;
		}
		else if (m_size <= (wantedSize / CAPACITY_FACTOR) && m_size != 0)
		{
			m_maxCapacity = m_maxCapacity / CAPACITY_FACTOR;
		}
		else
		{
			m_maxCapacity = wantedSize;
		}
		reallocate(m_maxCapacity);
	}

	void reallocate(int capacity)
	{
		if (capacity > 0)
		{
			Type* newBuffer = new Type[capacity];
			if (m_buffer != nullptr)
			{
				for (int i = 0; i < capacity; ++i)
				{
					newBuffer[i] = m_buffer[i];
				}
				delete m_buffer;
			}
			m_buffer = new Type[capacity];
			for (int i = 0; i < capacity; ++i)
			{
				m_buffer[i] = newBuffer[i];
			}
			delete newBuffer;
		}
	}

	//value swap for arrays based on int start index
	void swap(int startIndex)// change to shift
	{
		if (startIndex >= 0)
		{
			Type tmp = m_buffer[startIndex];
			m_buffer[startIndex] = m_buffer[startIndex - 1];
			m_buffer[startIndex - 1] = tmp;
		}
		else
		{
			startIndex = -startIndex;
			Type tmp = m_buffer[startIndex];
			m_buffer[startIndex] = m_buffer[startIndex + 1];
			m_buffer[startIndex + 1] = tmp;
		}
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