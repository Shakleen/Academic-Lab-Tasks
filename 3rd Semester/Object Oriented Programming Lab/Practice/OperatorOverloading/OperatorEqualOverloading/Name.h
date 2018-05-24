#pragma once
class Name
{
	char *name;
public:
	Name() { name = '\0'; };
	Name(const Name &obj);
	Name(const char *str);
	~Name() { delete[] name; }
	Name operator=(Name obj);
	char *getname() { return name; }
};

