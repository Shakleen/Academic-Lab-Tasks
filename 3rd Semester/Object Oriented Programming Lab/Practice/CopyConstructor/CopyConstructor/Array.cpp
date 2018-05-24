#include <cstring>
#include "Array.h"


Array::Array()
{
	Name = '\0';
}

Array::Array(const char * str)
{
	int len = strlen(str);
	Name = new char[len];
	for (int i = 0; i < len; i++)
	{
		Name[i] = str[i];
	}
	Name[len] = '\0';
}

Array::Array(const Array & obj)
{
	int len = strlen(obj.Name);
	Name = new char[len];
	for (int i = 0; i < len; i++)
	{
		Name[i] = obj.Name[i];
	}
	Name[len] = '\0';
}

Array::~Array()
{
	delete[] Name;
}
