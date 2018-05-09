#include <iostream>
#include "MyString.h"

using namespace std;

int main()
{
	// Normal constructor
	MyString obj1;
	obj1.PrintStr();

	// Parameterized constructor
	MyString obj((char*)"Rocks!");
	obj.PrintStr();

	// Copy constructor
	MyString OOP(obj);
	OOP.PrintStr();

	// Concat function
	MyString obj2((char*)"Ishfar");
	obj2 = obj2.Concat(obj);
	obj2.PrintStr();

	// Copy function
	MyString obj3;
	obj3 = obj3.Copy(obj2);
	obj3.PrintStr();
		
	system("pause");

	return 0;
}