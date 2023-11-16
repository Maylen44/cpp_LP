#include <cassert>
#include "String.h"

//calculate number of digits in int == number of char needed in str
static int countIntLength(int value)
{
	int digitCount = 1;
	int temp = value;
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
static void copyValue(char* destination, const char* source, int size)
{
	for (int i = 0; i < size; ++i)
	{
		destination[i] = source[i];
	}
}

//copy values from String to a new buffer from String
static void copyValue(char* destination, char* source, int size)
{
	for (int i = 0; i < size; ++i)
	{
		destination[i] = source[i];
	}
}

//copy values from String to a new buffer from String starting from specified index
static void copyValue(char* destination, char* source, int size, int startIndex)
{
	for (int i = 0; i < size; ++i)
	{
		destination[i + startIndex] = source[i];
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
	assert(cString != nullptr && "ERROR: trying to acces a nullptr cString");

	size = getLength(cString);
	buffer = new char[size];
	copyValue(this->buffer, cString, size);
}

//constructor transform from int
String::String(int value)
{
	assert(value < 32767 || value > -32767 && "ERROR: trying to pass exceeded value for int data typ range");

	int maxLength = countIntLength(value);
	bool isNegativ = false;
	buffer = new char[maxLength];
	size = 0;
	if (value == 0)
	{
		buffer[0] = '0';
		++size;
	}
	else
	{
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
		reverse(this->buffer, size);
	}
}

//constructor copy
String::String(const String& other)
{
	assert(this != &other || &other != nullptr && "ERROR: trying to construct copy of the same string or trying to acces a nullptr string");

	size = other.size;
	buffer = new char[other.size];
	for (int i = 0; i < other.size; ++i)
	{
		buffer[i] = other.buffer[i];
	}
}

//destructor
String::~String()
{
	assert(this != nullptr && "ERROR: trying to deconstruct a nullptr string");

	delete buffer;
	buffer = nullptr;
	size = -1;
}

//operator = for copy/assignment of strings
String& String::operator=(String& other)
{
	assert(this != nullptr || &other != nullptr && "ERROR: trying to acces nullptr string");

	size = other.size;
	buffer = new char[size];
	copyValue(this->buffer, other.buffer, size);
	return *this;
}

//operator = for concatenation of strings
String String::operator+(String& other)
{
	assert(this != nullptr || &other != nullptr && "ERROR: trying to acces nullptr string");

	String string;
	string.size = size + other.size;
	string.buffer = new char[string.size];
	for (int i = 0; i < string.size; ++i)
	{
		if (i < size)
		{
			copyValue(string.buffer, this->buffer, this->size);
		}
		else
		{
			copyValue(string.buffer, other.buffer, other.size, this->size);
		}
	}
	return string;
}

//operator < for comparing strings
bool String::operator<(String& other)
{
	assert(this != nullptr || &other != nullptr && "ERROR: trying to acces nullptr string");

	int minLength = (size < other.size) ? size : other.size;
	for (int i = 0; i < minLength; ++i)
	{
		if (buffer[i] < other.buffer[i])
		{
			return true;
		}
		else if (buffer[i] > other.buffer[i])
		{
			return false;
		}
	}
	if (size < other.size)
	{
		return true;
	}
	return false;
}

//operator < for comparing strings
bool String::operator>(String& other)
{
	assert(this != nullptr || &other != nullptr && "ERROR: trying to acces nullptr string");

	return !(*this < other);
}

//operator == for comparing equality by strings
bool String::operator==(String& other)
{
	assert(this != nullptr || &other != nullptr && "ERROR: trying to acces nullptr string");

	if (*this < other || *this > other)
	{
		return false;
	}
	return true;
}

//operator != for comparing equality by strings
bool String::operator!=(String& other)
{
	assert(this != nullptr || &other != nullptr && "ERROR: trying to acces nullptr string");

	return !(*this == other);
}

//function for printing
std::ostream& operator<<(std::ostream& os, String& string)
{
	assert(&string != nullptr && "ERROR: trying to acces nullptr string");

	for (int i = 0; i < string.size; ++i)
	{
		os << string.buffer[i];
	}
	return os;
}