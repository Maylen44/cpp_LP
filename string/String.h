#ifndef STRING_H
#define STRING_H
#include <iostream>

enum StringComparison
{
	EQUAL,
	GREATER,
	LESSER,
	ARGUMENT_ERROR
};

struct String
{
	//fields
	int size;
	char* buffer;

	//constructors
	String(); //default
	String(const char* cString); //transform
	String(int value); //transform from int
	String(const String& other); //copy

	//destructor
	~String();

	//operators
	String& operator=(String& other); //copy/assignment
	String operator+(String& string2); //strcat arg1 + arg2 = arg3
	bool operator<(String& other); //isLess
	bool operator>(String& other); //isGreater
	bool operator==(String& other); //isEqual
	bool operator!=(String& other); //isUnequal

	//methods
	int strcmp(String& other);
};

//function for printing
std::ostream& operator<<(std::ostream& os, String& string); //print

#endif //STRING_H