#pragma once
#include "Person.h"
class Patient : protected Person
{
public:
	Patient() :Person(20) {

	}
	char* Diagnostics;
	char* HospitalName;
	float TestResult;
	int PatientID;

};

