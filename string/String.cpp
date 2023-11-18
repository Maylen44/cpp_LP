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
	size = other.size;
	buffer = new char[other.size];
	copyValue(buffer, other.buffer, size);
}

//destructor
String::~String()
{
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
	copyValue(string.buffer, this->buffer, this->size);
	copyValue(&string.buffer[this->size], other.buffer, other.size);
	return string;
}

//operator < for comparing strings
bool String::operator<(String& other)
{
	assert(this != nullptr || &other != nullptr && "ERROR: trying to acces nullptr string");

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
	assert(this != nullptr || &other != nullptr && "ERROR: trying to acces nullptr string");

	return !(*this < other);
}

//operator == for comparing equality by strings
bool String::operator==(String& other)
{
	assert(this != nullptr || &other != nullptr && "ERROR: trying to acces nullptr string");

	return !(*this < other || *this > other);
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