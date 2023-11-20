#ifndef ARRAY_H
#define ARRAY_H

struct Array
{
public:
	Array();
	Array(int capacity);
	Array(const Array& other);
	~Array();

	void push(int value);

	void print() const;
	int getSize() const { return m_size; }

//private:
	int m_size;
	int m_maxCapacity;
	int* m_buffer;
	int m_capacityFactor = 2;

};



#endif //ARRAY_H