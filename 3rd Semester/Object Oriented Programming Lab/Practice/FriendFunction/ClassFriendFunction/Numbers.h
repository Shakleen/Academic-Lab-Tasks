#pragma once
#include "Operations.h"

class Numbers
{
private:
	int number1, number2;

public:
	Numbers();
	Numbers(int x, int y);

	friend int Operations::Add(Numbers obj);
	friend int Operations::Sub(Numbers obj);
};

