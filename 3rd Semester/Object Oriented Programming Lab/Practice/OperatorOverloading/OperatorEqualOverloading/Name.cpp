#include "Name.h"
#include <iostream>
#include <cstring>


Name::Name(const Name & obj)
{
	int len = strlen(obj.name);

	name = new char[len+1];

	for (int i = 0; i < len; i++)
	{
		name[i] = obj.name[i];
	}

	name[len] = '\0';
}

Name::Name(const char * str)
{
	int len = strlen(str);

	name = new char[len];

	for (int i = 0; i < len; i++)
	{
		name[i] = str[i];
	}

	name[len] = '\0';
}

Name Name::operator=(Name obj)
{
	int len = strlen(obj.name);

	this->name = new char[len+1];

	for (int i = 0; i <= len; i++)
	{
		name[i] = obj.name[i];
	}

	//obj.name[len] = '\0';

//	std::cout << "HERE!\n";

	return *this;
}
