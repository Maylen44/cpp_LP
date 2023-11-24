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
		assert(capacity >= 0 & "ff");

		m_size = 0;
		m_maxCapacity = capacity;
		if (m_maxCapacity > 0)
		{
			m_buffer = new Type[m_maxCapacity];
		}
		++m_count;
	}

	//constructor copy
	Array(const Array& origin)
	{
		m_size = origin.m_size;
		m_maxCapacity = origin.m_maxCapacity;
		if (m_maxCapacity > 0)
		{
			m_buffer = new Type[m_maxCapacity];
			if (m_size > 0)
			{
				copyFrom(origin);
			}
		}
		++m_count;
	}

	//destructor
	~Array()
	{
		clear();
		--m_count;
	}

	//adding an element to arrays last element
	void addElement(Type value, int destinationIndex = -1)
	{
		if (m_size == m_maxCapacity)
		{
			increaseMaxCapacity();
			resize();
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
		clear(this, m_size);
		if (m_size <= (m_maxCapacity / CAPACITY_FACTOR) && m_size != 0)
		{
			decreaseMaxCapacity();
			resize();
		}
	}

	//assign one array to another one by operator =
	Array operator=(const Array& origin)
	{
		if (origin.m_size > 0)
		{
			reallocate(origin.m_maxCapacity);
			m_maxCapacity = origin.m_maxCapacity;
			m_size = origin.m_size;
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
			newArray.m_size = newSize - 2;
		}
		return newArray;
	}

	void print() const;
	int getSize() const { return m_size; }
	int getMaxCapacity() const { return m_maxCapacity; }
	Type getElement(int destinationIndex) const
	{
		assert(destinationIndex >= 0 && destinationIndex <= m_size - 1 && "ddd");

		return m_buffer[destinationIndex];
	}

private:
	//copy array elements to another array
	void copyFrom(const Array& origin, int startIndex = 0)
	{
		assert(startIndex < origin.m_size && "fff");

		for (int i = 0; i < m_size; ++i)
		{
			m_buffer[i] = origin.m_buffer[i];
		}
		//add resize if i copy more elements in smaller array
	}

	//rasize buffer with values intact 
	void resize() // add wanted size and reduce other functions
	{
		Type* newBuffer = new Type[m_maxCapacity];//check for maxCapacity > 0
		for (int i = 0; i < m_size; ++i)
		{
			newBuffer[i] = m_buffer[i];
		}
		reallocate(m_maxCapacity);
		for (int i = 0; i < m_size; ++i)
		{
			m_buffer[i] = newBuffer[i];
		}
		delete newBuffer;
	}

	//reallocate buffer to a new buffer with cleaning
	void reallocate(int capacity) //add resize function here and increase decreas capacity
	{
		if (m_buffer != nullptr)
		{
			delete m_buffer;
		}
		m_buffer = new Type[capacity];
	}

	//clearing function for whole object, just array values or specified array element (in conjunction with removeElement function)
	void clear(Array* origin = nullptr, int destinationIndex = -1) //naming index change to bool lastElement? better move into resize function
	{
		if (origin != nullptr && destinationIndex == -1)
		{
			m_size = -1;
			m_maxCapacity = 0;
		}
		else if (origin != nullptr && destinationIndex > -1 && destinationIndex <= m_size)
		{
			m_size = (m_size > 0) ? --m_size : 0;
		}
		else
		{
			if (m_buffer != nullptr)
			{
				delete m_buffer;
				m_buffer = nullptr;
			}
			m_size = -1;
			m_maxCapacity = -1;
		}
	}

	//increase array max capacity by scale factor
	void increaseMaxCapacity()//add this functions to reallocate
	{
		m_maxCapacity = (m_size == 0) ? (1 + m_maxCapacity) * CAPACITY_FACTOR : m_maxCapacity * CAPACITY_FACTOR;
	}

	//decrease array max capacity by scale factor
	void decreaseMaxCapacity()//add this functions to reallocate
	{
		m_maxCapacity = (m_size == 0) ? 0 : m_maxCapacity / CAPACITY_FACTOR;
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