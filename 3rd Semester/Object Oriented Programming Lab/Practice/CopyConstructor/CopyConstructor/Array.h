#pragma once
class Array
{
	char *Name;
public:
	Array();					// Default constructor
	Array(const char *str);		// Parameterized COnstructor
	Array(const Array &obj);	// Copy Constructor
	~Array();

	char *getName() { return Name; }
};

