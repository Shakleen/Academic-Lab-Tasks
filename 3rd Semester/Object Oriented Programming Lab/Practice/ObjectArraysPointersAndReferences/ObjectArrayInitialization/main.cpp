#include <iostream>
#include "A.h"
#include "B.h"

int main()
{
	A obj[3];									// Non-initialized. Default constructor used.
	A obj2[3] = { 1, 2, 3 };					// Initialized using short hand. Parameterized constructor used.
	B obj3[3] = { B(1,1), B(2,2), B(3,3) };		// Initiazlied using full form. Parameterized constructor used.

	for (int i = 0; i < 3; i++)
	{
		std::cout << "Obj[" << i << "].value = " << obj[i].value << std::endl;
	}

	for (int i = 0; i < 3; i++)
	{
		std::cout << "Obj2[" << i << "].value = " << obj2[i].value << std::endl;
	}

	for (int i = 0; i < 3; i++)
	{
		std::cout << "Obj3[" << i << "].value = " << obj3[i].value1 
			<< " Obj3[" << i << "].value2 = " << obj3[i].value2 << std::endl;
	}

	system("pause");
	return 0;
}