#pragma once
class Numbers
{
	int x, y;
public:
	Numbers(int x=0, int y=0) { this->x = x, this->y = y; }
	void setX(int x) { this->x = x; }
	void setY(int y) { this->y = y; }
	int getX() { return x; }
	int getY() { return y; }

	// Binary Operators
	Numbers operator+(Numbers ob2);
	Numbers operator-(Numbers ob2);
	Numbers operator*(Numbers ob2);
	Numbers operator/(Numbers ob2);
	Numbers operator=(Numbers ob2);
	
	// Unary operators
	Numbers operator++(int x);	// Postfix
	Numbers operator--(int x);	// Postfix
	Numbers operator++();		// Prefix
	Numbers operator--();		// Prefix
};

