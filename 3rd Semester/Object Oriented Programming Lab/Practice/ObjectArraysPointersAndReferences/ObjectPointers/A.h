#pragma once
class A
{
	int PrivateValue;
public:
	int PublicValue;
	A(int x, int y) { PublicValue = x, PrivateValue = y; }
};

