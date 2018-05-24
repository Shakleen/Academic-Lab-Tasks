#include <iostream>
#include "Numbers.h"

inline int Operations::Add(Numbers obj)
{
	return obj.number1 + obj.number2;
}

inline int Operations::Sub(Numbers obj)
{
	return obj.number1 - obj.number2;
}

int main()
{
	Numbers No(5, 2);

	Operations Op;

	std::cout << "Addition gives: " << Op.Add(No) << std::endl;
	std::cout << "Subtraction gives: " << Op.Sub(No) << std::endl;

	system("pause");
	return 0;
}