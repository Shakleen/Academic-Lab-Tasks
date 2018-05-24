#include <iostream>
#include "A.h"

void printValue(A obj)
{
	std::cout << "Private member: " << obj.Private << std::endl;
	std::cout << "Public member: " << obj.Public << std::endl;
	std::cout << "Protected member: " << obj.Protected << std::endl;
}

int sum(A obj)
{
	return obj.x + obj.y;
}

int main()
{
	A obj;

	printValue(obj);

	obj.setValue(3, 5);

	std::cout << "Sum: " << sum(obj) << std::endl;

	system("pause");
	return 0;
}