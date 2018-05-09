#include <iostream>

#include "GetterSetter.h"

using namespace std;


int main()
{
	GetterSetter PPObj;
	int i=PPObj.getPDateOfBirth();
	cout << i;
//	Patient PObj;
//	Employee EObj;
//	Student SObj;
//
//	// Setting up info
//	SObj.Department = (char*) "CSE";
//	cout << SObj.Department << "\n";
//
//	// SObj.FirstName = (char*) "Ishfar";
//
////	cout << PPObj.getPFirstName() << endl;
//
//	PPObj.setPDateOfBirth(399);
//
//	cout << PPObj.getPDateOfBirth() << endl;
//
	system("pause");

	return 0;

}