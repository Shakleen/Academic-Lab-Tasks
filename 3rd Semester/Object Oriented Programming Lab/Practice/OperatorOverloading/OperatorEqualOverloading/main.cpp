#include <iostream>
#include "Name.h"

int main()
{
	Name Name1("Ishfar"), Name2;

	std::cout << Name1.getname() << std::endl;

	Name2 = Name1;

	std::cout << Name2.getname() << std::endl;

	system("pause");
	return 0;
}