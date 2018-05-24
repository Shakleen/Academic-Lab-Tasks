#pragma once
#include <iostream>

class A
{
	int value = 0;
public:
	A(int x) { value = x; }
	~A() { std::cout << "Destructing!" << std::endl; system("pause"); }
	void setValue(int x) { value = x; }
	int getValue() { return value; }
};

