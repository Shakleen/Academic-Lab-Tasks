#include <iostream>
#include "Array.h"

int main()
{
	Array obj("Ishrak"), obj2(obj);

	std::cout << "Obj has " << obj.getName() << std::endl;

	std::cout << "Obj2 has " << obj2.getName() << std::endl;

	system("pause");
	return 0;
}