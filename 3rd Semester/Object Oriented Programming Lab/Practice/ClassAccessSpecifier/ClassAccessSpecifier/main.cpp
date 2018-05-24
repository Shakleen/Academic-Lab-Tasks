#include <iostream>
#include "A.h"

int main()
{
	A obj;

	// obj.Private;			// Not accessible outside class
	// obj.Protected;		// Not accessible outside class

	std::cout << obj.Public << std::endl;

	system("pause");

	return 0;
}