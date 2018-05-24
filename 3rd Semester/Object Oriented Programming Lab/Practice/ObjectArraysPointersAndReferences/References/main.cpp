#include <iostream>
#include "A.h"

void SquareIt(A &obj)
{
	std::cout << "In SquareIt Function!\n";

	obj.setValue( obj.getValue() * obj.getValue() );
}

int main()
{
	A obj(10);

	std::cout << "In main value of obj.Value is " << obj.getValue() << std::endl;

	SquareIt(obj);

	std::cout << "In main value of obj.Value is " << obj.getValue() << std::endl;

	return 0;
}