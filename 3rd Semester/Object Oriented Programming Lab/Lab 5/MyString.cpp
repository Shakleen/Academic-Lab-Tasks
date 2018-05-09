#include "MyString.h"

MyString::MyString()
{
	str = (char*)"";
	size = 0;
}

MyString::MyString(char * str2)
{
	size = strlen(str2);

	str = new char[sizeof(char) * size];

	strcpy(str, str2);
}

MyString::MyString(const MyString & obj)
{
	size = obj.size;

	str = new char[sizeof(char) * size];

	strcpy(str, obj.str);
}


MyString::~MyString()
{
	// printf("DESTROYED!\n");
	// delete str;
	// delete &size;
}

MyString MyString::Copy(MyString obj)
{
	*this = obj;

	return *this;
}

MyString MyString::Concat(MyString obj)
{
	int len = strlen(obj.str);

	char *str2 = new char[sizeof(char) * (len + size)];

	strcpy(str2, str);
	strcat(str2, obj.str);

	str = new char[sizeof(char) * (len + size)];
	strcpy(str, str2);

	return *this;
}

void MyString::PrintStr()
{
	printf("%s\n", str);
}

