#pragma once
class A
{
private:
	int x, y;
public:
	A();		// Default constructor
	A(int x);   // One Parameter COnstructor
	A(int x, int y);
	int getX() { return x; }
	int getY() { return y; }
	~A();
};

