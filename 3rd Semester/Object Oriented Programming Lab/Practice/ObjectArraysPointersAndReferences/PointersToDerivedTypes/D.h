#pragma once
#include "B.h"
class D : public B
{
	int DerivedValue;
public:
	D(int x) { DerivedValue = x; }
	int getDeivedValue() { return DerivedValue; }
};

