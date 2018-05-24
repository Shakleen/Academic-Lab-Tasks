#include "Numbers.h"
#include <iostream>

Numbers Numbers::operator+(Numbers ob2)
{
	std::cout << "Overloaded + used " << std::endl;
	Numbers temp;
	temp.setX(x + ob2.getX());
	temp.setY(y + ob2.getY());
	return temp;
}

Numbers Numbers::operator-(Numbers ob2)
{
	std::cout << "Overloaded - used " << std::endl;
	Numbers temp;
	temp.setX(x - ob2.getX());
	temp.setY(y - ob2.getY());
	return temp;
}

Numbers Numbers::operator*(Numbers ob2)
{
	std::cout << "Overloaded * used " << std::endl;
	Numbers temp;
	temp.setX(x * ob2.getX());
	temp.setY(y * ob2.getY());
	return temp;
}

Numbers Numbers::operator/(Numbers ob2)
{
	std::cout << "Overloaded / used " << std::endl;
	Numbers temp;
	temp.setX(x / ob2.getX());
	temp.setY(y / ob2.getY());
	return temp;
}

Numbers Numbers::operator=(Numbers ob2)
{
	std::cout << "Overloaded = used " << std::endl;
	this->setX(ob2.getX());
	this->setY(ob2.getY());
	return *this;
}

Numbers Numbers::operator++(int x)
{
	std::cout << "Overloaded ++ Postfix used " << std::endl;
	this->x++;
	this->y++;
	return *this;
}

Numbers Numbers::operator--(int x)
{
	std::cout << "Overloaded -- Postfix used " << std::endl;
	this->x--;
	this->y--;
	return *this;
}

Numbers Numbers::operator++()
{
	std::cout << "Overloaded ++ prefix used " << std::endl;
	this->x++;
	this->y++;
	return *this;
}

Numbers Numbers::operator--()
{
	std::cout << "Overloaded -- prefix used " << std::endl;
	this->x--;
	this->y--;
	return *this;
}