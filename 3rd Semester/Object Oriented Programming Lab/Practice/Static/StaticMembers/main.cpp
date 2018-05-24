#include <iostream>
#include "A.h"

int A::counter;	// Defined here

int main()
{
	A::counter = 0;

	A obj;
	std::cout << "Number of objects of type A : " << A::counter << std::endl;

	A obj2;
	std::cout << "Number of objects of type A : " << A::counter << std::endl;

	A obj3;
	std::cout << "Number of objects of type A : " << A::counter << std::endl;

	// system("pause");
	return 0;
}