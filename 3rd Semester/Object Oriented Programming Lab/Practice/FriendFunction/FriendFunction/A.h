#pragma once
class A
{
public:
	int Public = 1;
	void setValue(int x, int y) { this->x = x, this->y = y; }
private:
	int Private = 0;
	int x = 0, y = 0;
protected:
	int Protected = 2;

	friend void printValue(A obj);
	friend int sum(A obj);
};

