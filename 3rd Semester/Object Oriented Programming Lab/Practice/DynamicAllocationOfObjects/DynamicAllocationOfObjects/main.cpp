#include <iostream>
#include <new>
#include "A.h"

int main()
{
	A *obj, *ObjA;

	try {
		ObjA = new A[3];	// Can't initialize array when made with new
	}
	catch (std::bad_alloc xa) {
		std::cout << "Allocation not possible!" << std::endl;
		return 1;
	}

	for (int i = 0; i < 3; i++)
	{
		ObjA[i].setVal(i);
	}

	for (int i = 0; i < 3; i++)
	{
		std::cout << "Value of " << i << " is " << ObjA[i].getX() << std::endl;
	}

	try{
		obj = new A(10);
	}
	catch (std::bad_alloc xa) {
		std::cout << "Allocation not possible!" << std::endl;
		return 1;
	}

	std::cout << "Value of single object is " << obj->getX() << std::endl;

	system("pause");

	return 0;
}