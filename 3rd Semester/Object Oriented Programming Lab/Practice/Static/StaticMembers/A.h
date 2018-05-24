#pragma once

#include <iostream>

class A
{
public:
	A() { counter++; }
	~A() { std::cout << "Number of objects of type A : " << --(A::counter) << std::endl; system("pause"); }
	static int counter;
};

