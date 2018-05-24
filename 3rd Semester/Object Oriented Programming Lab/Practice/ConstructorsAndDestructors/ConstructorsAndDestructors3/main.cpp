#include <iostream>
#include "A.h"


void Func(A obj)
{
	std::cout << "Func called!" << std::endl;
}

A Func2()
{
	std::cout << "In func2!" << std::endl;

	A temp;

	return temp;
}

int main()
{
	A obj;

	std::cout << "In main first time!" << std::endl;

	Func(obj);

	std::cout << "In main second time!" << std::endl;

	A obj3 = Func2();

	std::cout << "In main third time!" << std::endl;

	return 0;
}