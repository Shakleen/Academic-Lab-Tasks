#pragma once
#include <cstring>
#include <cstdio>

class MyString
{
public:
	MyString();
	MyString(char* str2);
	MyString(const MyString &obj);
	~MyString();
	MyString Copy(MyString obj);
	MyString Concat(MyString obj);
	void PrintStr();

private:
	char* str;
	int size;
};

