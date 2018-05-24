#pragma once
class A
{
	int val;
public:
	A() { val = 0; }
	A(int x) { val = x; }
	~A() { delete this; }
	void setVal(int x) { val = x; }
	int getX() { return val; }
};

