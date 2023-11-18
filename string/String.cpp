#include <cassert>
#include "String.h"

//calculate number of digits in int == number of char needed in str
static int countIntLength(int value)
{
	int digitCount = 1;
	int temp = ++value;
	while (temp != 0)
	{
		temp /= 10;
		++digitCount;
	}
	return digitCount;
}

//calculate length of the cString
static int getLength(const char* cString)
{
	int length = 0;
	while (cString[length] != '\0')
	{
		length++;
	}
	return length;
}

//copy values from cString to a new buffer from String struct
static void copy(char* destination, const char* source, int size)
{
	for (int i = 0; i < size; ++i)
	{
		destination[i] = source[i];
	}
}

//reverse values of a String
static void reverse(char* origin, int size)
{
	for (int i = 0; i < size / 2; ++i)
	{
		char temp = origin[i];
		origin[i] = origin[size - i - 1];
		origin[size - i - 1] = temp;
	}
}

//constructor default
String::String()
{
	size = 0;
	buffer = nullptr;
}

//constructor transform
String::String(const char* cString)
{
	size = getLength(cString);
	buffer = new char[size];
	copy(this->buffer, cString, size);
}

//constructor transform from int
String::String(int value)
{
	int maxLength = countIntLength(value);
	bool isNegativ = false;
	buffer = new char[maxLength];
	size = 0;

	if (value < 0)
	{
		isNegativ = true;
		value = -value;
	}
	for (int i = 0; i < maxLength - 1; ++i)
	{
		int digit = value % 10;
		buffer[size++] = '0' + digit;
		value /= 10;
	}
	if (isNegativ)
	{
		buffer[size++] = '-';
	}
	reverse(buffer, size);
}

//constructor copy
String::String(const String& other)
{
	size = other.size;
	buffer = new char[other.size];
	copy(buffer, other.buffer, size);
}

//destructor
String::~String()
{
	if (buffer != nullptr)
	{
		delete buffer;
		buffer = nullptr;
	}
	size = -1;
}

//operator = for copy/assignment of strings
String& String::operator=(String& other) //CHECK THIS ONE MORE TIME
{
	if (size > 0 || this != &other)
	{
		size = other.size;
		buffer = new char[size];
		copy(buffer, other.buffer, size);
		return *this;
	}
}

//operator = for concatenation of strings
String String::operator+(String& other)
{
	String string;
	string.size = size + other.size;
	string.buffer = new char[string.size];
	copy(string.buffer, buffer, size);
	copy(string.buffer + size, other.buffer, other.size);
	return string;
}

//operator < for comparing strings
bool String::operator<(String& other)
{
	int minLength = (size < other.size) ? size : other.size;
	bool result = false;
	for (int i = 0; i < minLength; ++i)
	{
		if (buffer[i] < other.buffer[i])
		{
			result = true;
			break;
		}
		else if (buffer[i] > other.buffer[i])
		{
			result = false;
			break;
		}
	}
	if (size < other.size)
	{
		result = true;
	}
	return result;
}

//operator < for comparing strings
bool String::operator>(String& other)
{
	return other < *this;
}

//operator == for comparing equality by strings
bool String::operator==(String& other)
{
	return !(*this < other || *this > other);
}

//operator != for comparing equality by strings
bool String::operator!=(String& other)
{
	return !(*this == other);
}

//function for printing
std::ostream& operator<<(std::ostream& os, String& string)
{
	assert(&string != nullptr && "ERROR: Trying to print nullptr string");

	for (int i = 0; i < string.size; ++i)
	{
		os << string.buffer[i];
	}
	return os;
}