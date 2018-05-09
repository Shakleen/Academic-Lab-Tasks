#pragma once

#include "Person.h"

class Employee : protected Person
{
public:
	Employee():Person(10){

	}
	int EmpID;
	int Salary;
	char* Organization;
	char* Designation;

};

