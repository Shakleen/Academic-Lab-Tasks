#include <iostream>
#include "A.h"

int main()
{
	int A::*PublicData;				// Declaring Data Member Pointer
	PublicData = &A::PublicValue;	// Initializing Data Member Pointer to a certain member variable

	int (A::*Func)();				// Declaring Function Member pointer
	Func = &A::Square;				// Initializing Function member pointer to a certain member function
	
	/*
		Invalid code
		int A::*PrivateData;
		PrivateData = &A::PrivateValue; // Can't access private values
	*/

	A obj(1, 2), *pObj = &obj;
	std::cout << "Data Member Pointer: " << std::endl;
	std::cout << "Showing through object: " << obj.*PublicData << std::endl; // Using member pointer through object
	std::cout << "Showing through pointer: " << pObj->*PublicData << std::endl; // Using member pointer through pointer to object

	std::cout << std::endl << "Function member pointer:" << std::endl;
	std::cout << "Calling through object: " << (obj.*Func)() << std::endl; // Using member pointer through object
	std::cout << "Calling through pointer: " << (pObj->*Func)() << std::endl; // Using member pointer through pointer to object

	A obj2(4, 6), *pObj2 = &obj2;
	std::cout << "Data Member Pointer: " << std::endl;
	std::cout << "Showing through object: " << obj2.*PublicData << std::endl; // Using member pointer through object
	std::cout << "Showing through pointer: " << pObj2->*PublicData << std::endl; // Using member pointer through pointer to object

	std::cout << std::endl << "Function member pointer:" << std::endl;
	std::cout << "Calling through object: " << (obj2.*Func)() << std::endl; // Using member pointer through object
	std::cout << "Calling through pointer: " << (pObj2->*Func)() << std::endl; // Using member pointer through pointer to object

	system("pause");
	return 0;
}