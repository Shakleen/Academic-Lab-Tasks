#include <iostream>
#include "A.h"

int main()
{
	A obj,				// Default contructor called
	obj2 = A(20),		// Copy constructor called
	obj3(30),			// One parameter constructor called
	obj4 = 40,			// Special case works for only one parameter
	obj5(10, 20);		// Two parameter constructor called

	std::cout << obj.getX() << std::endl;
	std::cout << obj2.getX() << std::endl;
	std::cout << obj3.getX() << std::endl;
	std::cout << obj4.getX() << std::endl;
	std::cout << obj5.getX() << obj5.getY() << std::endl;

	return 0;
}