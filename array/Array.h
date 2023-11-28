#ifndef ARRAY_H
#define ARRAY_H
#include <cassert>

const int CAPACITY_FACTOR = 2;

template<typename Type> class Array
{
public:
	Array(int capacity = 0)
	: m_maxCapacity(capacity)
	, m_size(0)
	{
		assert(capacity >= 0 && "ERROR: Initializing a new array with negativ capacity.");

		if (m_maxCapacity > 0)
		{
			m_buffer = new Type[m_maxCapacity];
		}
	}

	Array(const Array& origin)
	{
		if (origin.m_maxCapacity > 0 && origin.m_size > 0)
		{
			copyFrom(origin);
		}
	}

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

	void addElement(Type value, int destinationIndex = -1)
	{
		if (m_size == m_maxCapacity)
		{
			resize(m_maxCapacity);
		}
		m_buffer[m_size++] = value;

		if(destinationIndex > -1 && destinationIndex < m_size)
		{
			swap(m_size - 1, destinationIndex);
		}
	}

	void removeElement(int destinationIndex = -1)
	{
		if (destinationIndex > -1 && destinationIndex < m_size)
		{
			swap(destinationIndex, m_size - 1);
		}
		m_size = (m_size > 0) ? --m_size : m_size;
	}

	void shift(int startIndex, int numOfElements, int offset)
	{
		//var 1: increase bunduries of array
		/*
		if (startIndex >= 0 && startIndex < m_size && offset != 0 && numOfElements > 0)
		{
			if (offset > 0)
			{
				int neededCapacity = startIndex + numOfElements + offset;
				if (neededCapacity > m_maxCapacity)
				{
					resize(neededCapacity);
				}
				for (int i = numOfElements - 1; i >= 0; --i)
				{
					m_buffer[startIndex + i + offset] = m_buffer[startIndex + i];
				}
				m_size = (m_size < neededCapacity) ? neededCapacity : m_size;
			}
			else
			{
				int offsetResult = startIndex + offset;
				if (offsetResult < 0)
				{
					offsetResult = -offsetResult;
					resize(m_maxCapacity + offsetResult);
					shift(0, m_size, offsetResult);
					startIndex += offsetResult;
				}
				for (int i = 0; i < numOfElements; ++i)
				{
					m_buffer[startIndex + offset + i] = m_buffer[startIndex + i];
				}
			}
		}
		*/

		//var 2: overscroll the bunduries of array and start from beginning/end
		/*
		if (startIndex >= 0 && startIndex < m_size && offset != 0 && numOfElements > 0)
		{
			if (offset > 0)
			{
				for (int i = numOfElements - 1; i >= 0; --i)
				{
					int offsetResult = startIndex + offset + i - m_size + 1;

					if (offsetResult > 0)
					{
						m_buffer[0 + offsetResult - 1] = m_buffer[startIndex + i];
					}
					else
					{
						m_buffer[startIndex + offset + i] = m_buffer[startIndex + i];
					}
					startIndex = ((startIndex + i) < m_size) ? startIndex : 0;
				}
			}
			else
			{
				for (int i = 0; i < numOfElements; ++i)
				{
					int offsetResult = startIndex + offset;
					if (offsetResult < 0)
					{
						m_buffer[m_size + offsetResult] = m_buffer[startIndex];
					}
					else
					{
						m_buffer[startIndex + offset] = m_buffer[startIndex];
					}
					startIndex++;
					startIndex = (startIndex < m_size) ? startIndex : 0;
				}
			}
		}
		*/

		//var 3: dont increase and dont scroll. if its in the bunduries good else dont overwrite trash
		if (startIndex >= 0 && startIndex < m_size && offset != 0 && numOfElements > 0)
		{
			for (int i = numOfElements - 1; i >= 0; --i)
			{
				int offsetResult = startIndex + offset + i;
				if (offsetResult < m_size && offsetResult >= 0)
				{
					m_buffer[startIndex + offset + i] = m_buffer[startIndex + i];
				}
			}
		}
	}

	//add shrinkToFit function

	Array& operator=(const Array& origin)
	{
		if (origin.m_size > 0)
		{
			m_size = 0;
			copyFrom(origin);
		}
		return *this;
	}

	Array operator+(const Array& rhs)
	{
		Array<Type> newArray(m_size + rhs.m_size);
		if ((m_size + rhs.m_size) > 0)
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

	void resize(int wantedCapacity)
	{
		if (m_size == wantedCapacity)
		{
			m_maxCapacity = (m_size == 0) ? (1 + m_maxCapacity) * CAPACITY_FACTOR : m_maxCapacity * CAPACITY_FACTOR;
		}
		else
		{
			m_maxCapacity = wantedCapacity;
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
			m_buffer = newBuffer;
		}
	}

	void swap(int startIndex, int destinationIndex)
	{
		if (startIndex >= 0 && startIndex != destinationIndex)
		{
			if (startIndex > destinationIndex)
			{
				assert(startIndex < m_size && "ERROR: Trying to access element on invalid index");

				for (int i = startIndex; i > destinationIndex; --i)
				{
					Type tmp = m_buffer[i];
					m_buffer[i] = m_buffer[i - 1];
					m_buffer[i - 1] = tmp;
				}
			}
			else
			{
				assert(destinationIndex < m_size && "ERROR: Trying to access element on invalid index");

				for (int i = startIndex; i < destinationIndex; ++i)
				{
					Type tmp = m_buffer[i];
					m_buffer[i] = m_buffer[i + 1];
					m_buffer[i + 1] = tmp;
				}
			}
		}
	}

	int m_maxCapacity;
	int m_size;
	Type* m_buffer;
};

template<typename Type>
void Array<Type>::print() const
{
	for (int i = 0; i < this->m_size; ++i)
	{
		std::cout << this->m_buffer[i] << std::endl;
	}
}

#endif //ARRAY_H