#include <cassert>
#include "String.h"

//calculate number of digits in int == number of char needed in str
static int countIntLength(int value)
{
	int digitCount = 0;
	int temp = value;

	if (value == 0)
	{
		digitCount = 1;
	}
	else if (value < 0)
	{
		while (temp < 0)
		{
			temp /= 10;
			++digitCount;
		}
	}
	else
	{
		while (temp > 0)
		{
			temp /= 10;
			++digitCount;
		}
	}
	return digitCount;
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
	size = 0;
	while (cString[size] != '\0')
	{
		size++;
	}
	buffer = new char[size];
	for (int i = 0; cString[i] != '\0'; ++i)
	{
		buffer[i] = cString[i];
	}
}

//constructor transform from int
String::String(int value)
{
	buffer = new char[countIntLength(value) + 1];

	bool isNegative = false;
	int index = 0;

	if (value == 0)
	{
		buffer[0] = '0';
		size = 1;
	}
	if (value < 0)
	{
		isNegative = true;
		value = -value;
	}
	while (value > 0)
	{
		int digit = value % 10;
		buffer[index++] = '0' + digit;
		value /= 10;
	}
	if (isNegative)
	{
		buffer[index++] = '-';
	}
	for (int i = 0; i < index / 2; ++i)
	{
		char temp = buffer[i];
		buffer[i] = buffer[index - i - 1];
		buffer[index - i - 1] = temp;
	}
	size = index;
}

//constructor copy
String::String(const String& other)
{
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
	delete buffer;
	buffer = nullptr;
	size = -1;
}

//operator = for copy/assignment of strings
String& String::operator=(String& other)
{
	size = other.size;
	buffer = new char[other.size];
	for (int i = 0; i < other.size; ++i)
	{
		buffer[i] = other.buffer[i];
	}
	return *this;
}

//operator = for concatenation of strings
String String::operator+(String& string2)
{
	String string;
	string.size = size + string2.size;
	string.buffer = new char[string.size];
	for (int i = 0; i < string.size; ++i)
	{
		if (i < size)
		{
			string.buffer[i] = buffer[i];
		}
		else
		{
			string.buffer[i] = string2.buffer[i - size];
		}
	}
	return string;
}

//operator < for comparing strings
bool String::operator<(String& other)
{
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
	else if (size > other.size)
	{
		return false;
	}
	return false; //in case of equality
}

//operator < for comparing strings
bool String::operator>(String& other)
{
	int minLength = (size < other.size) ? size : other.size;
	for (int i = 0; i < minLength; ++i)
	{
		if (buffer[i] < other.buffer[i])
		{
			return false;
		}
		else if (buffer[i] > other.buffer[i])
		{
			return true;
		}
	}
	if (size < other.size)
	{
		return false;
	}
	else if (size > other.size)
	{
		return true;
	}
	return false; //in case of equality
}

//operator == for comparing equality by strings
bool String::operator==(String& other)
{
	if (*this < other || *this > other)
	{
		return false;
	}
	return true;
}

//operator != for comparing equality by strings
bool String::operator!=(String& other)
{
	if (*this < other || *this > other)
	{
		return true;
	}
	return false;
}

//method for string comparison
int String::strcmp(String& other)
{
	int result = EQUAL;
	int totalSize = size + other.size;

	if (buffer == nullptr || other.buffer == nullptr)
	{
		result = ARGUMENT_ERROR;
	}
	else if (*this == other)
	{
		result = EQUAL;
	}
	else
	{
		if (*this < other)
		{
			result = LESSER;
		}
		else
		{
			result = GREATER;
		}
	}
	return result;
}

//function for printing
std::ostream& operator<<(std::ostream& os, String& string)
{
	for (int i = 0; i < string.size; ++i)
	{
		os << string.buffer[i];
	}
	return os;
}