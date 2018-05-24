#pragma once
class B
{
	int BaseValue;
public:
	B() { BaseValue = 0; }
	B(int x) { BaseValue = x; }
	int getBaseValue() { return BaseValue; }
};

