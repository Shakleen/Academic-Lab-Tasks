#include <iostream>
#include "Numbers.h"

int main()
{
	Numbers obj1(10, 20), obj2(30, 40);

	// Testing Operator + overlaod
	std::cout << "X = " << (obj1 + obj2).getX() << " Y = " << (obj1 + obj2).getY() << std::endl;

	// Testing Operator - overlaod
	std::cout << "X = " << (obj1 - obj2).getX() << " Y = " << (obj1 - obj2).getY() << std::endl;

	// Testing Operator * overlaod
	std::cout << "X = " << (obj1 * obj2).getX() << " Y = " << (obj1 * obj2).getY() << std::endl;

	// Testing Operator / overlaod
	std::cout << "X = " << (obj1 / obj2).getX() << " Y = " << (obj1 / obj2).getY() << std::endl;

	// Testing Operator = overload
	obj1 = obj2;
	std::cout << "X = " << obj1.getX() << " Y = " << obj1.getY() << std::endl;

	// Testing Operator ++ Prefix Overload
	++obj1;
	std::cout << "X = " << obj1.getX() << " Y = " << obj1.getY() << std::endl;

	// Testing Operator -- Prefix Overload
	--obj1;
	std::cout << "X = " << obj1.getX() << " Y = " << obj1.getY() << std::endl;

	// Testing Operator ++ Postfix Overload
	obj1++;
	std::cout << "X = " << obj1.getX() << " Y = " << obj1.getY() << std::endl;

	// Testing Operator -- Postfix Overload
	obj1--;
	std::cout << "X = " << obj1.getX() << " Y = " << obj1.getY() << std::endl;

	system("pause");
	return 0;
}