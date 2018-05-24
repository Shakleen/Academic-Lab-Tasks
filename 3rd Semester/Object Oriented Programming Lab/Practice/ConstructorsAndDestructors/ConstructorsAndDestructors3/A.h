#pragma once

#include <iostream>

class A
{
	static int val;
public:
	A() { std::cout << "Consructing!" << std::endl; }
	~A() { std::cout << "Destructing " << std::endl; system("pause"); };
};

