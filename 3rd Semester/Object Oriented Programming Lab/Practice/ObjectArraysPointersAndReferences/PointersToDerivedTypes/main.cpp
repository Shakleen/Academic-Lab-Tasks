#include <iostream>
#include "D.h"

int main()
{
	B *BasePointer;
	B BaseObject(10);
	D DerivedObject(30);

	BasePointer = &BaseObject; // Valid

	std::cout << BasePointer->getBaseValue() << std::endl;
	
	BasePointer = &DerivedObject; // Valid

	std::cout << BasePointer->getBaseValue() << std::endl;
	// std::cout << BasePointer->getDerivedValue() << std::endl; // Doesn't work

	std::cout << ((D*)BasePointer)->getDeivedValue << std::endl; // Valid

	system("pause");
	return 0;
}