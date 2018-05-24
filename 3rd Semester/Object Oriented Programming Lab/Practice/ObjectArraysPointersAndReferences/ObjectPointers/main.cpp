#include <iostream>
#include "A.h"

int main()
{
	A obj[3] = { A(1,1),A(2,2),A(3,3) };
	A *pObj = obj;					// Pointer of type Class A
	int *pInt = &obj[0].PublicValue;// Pointer of type int. Pointing to PUBLIC member of object obj[0]

	for (int i = 0; i < 3; i++)
	{
		std::cout << pObj->PublicValue << std::endl;
		pObj++;
	}

	std::cout << "Member vaiable PublicValue of obj[0]: " << *pInt << std::endl;

	system("pause");
	return 0;
}