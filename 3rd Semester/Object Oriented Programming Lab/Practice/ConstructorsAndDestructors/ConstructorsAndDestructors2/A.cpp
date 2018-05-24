#include "A.h"
#include <iostream>


A::A(int x)
{
	val = x;
	std::cout << "Constructing " << val << "!" << std::endl;
}


A::~A()
{
	std::cout << "Destructing " << val << "!" << std::endl;
	system("pause");
}
