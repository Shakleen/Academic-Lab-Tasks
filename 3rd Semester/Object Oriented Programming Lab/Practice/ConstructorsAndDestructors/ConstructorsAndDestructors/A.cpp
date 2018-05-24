#include "A.h"
#include <iostream>

A::A()
{
	x = 0;
}

A::A(int x)
{
	this->x = x;
}

A::A(int x, int y)
{
	this->x = x;
	this->y = y;
}


A::~A()
{
	std::cout << "Destructing" << x << "!" << std::endl;
	system("pause");
}
