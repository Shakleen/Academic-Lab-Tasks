#pragma once
#include "cstdlib"
#include "cstring"
#include "Person.h"

class Student : protected Person
{
public:
	Student() :Person(30) {}
	double cgpa;
	int StudentID;
	char* Department;
	int CurrentSemester;
};

