#ifndef ARRAY_H
#define ARRAY_H

const int CAPACITY_FACTOR = 2;

struct Array
{
public:
	Array();
	Array(int capacity);
	Array(const Array& origin);
	~Array();

	void push(int value);
	void pop();

	void print() const;
	int getSize() const { return m_size; }

private:
	void copyFrom(const Array& origin);
	void increaseMaxCapacity();
	void decreaseMaxCapacity();

	int m_size;
	int m_maxCapacity;
	int* m_buffer;
};

#endif //ARRAY_H