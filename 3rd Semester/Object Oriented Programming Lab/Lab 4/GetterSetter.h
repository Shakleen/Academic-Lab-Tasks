#pragma once

#include "cstdlib"
#include "Employee.h"
#include "Patient.h"
#include "Student.h"

class GetterSetter : private Patient, private Student, private Employee
{
public:
	void printDoB()
	{
		cout << DateOfBirth << "\n";
	}
	
	//// Getters

	///// Getters for Person portion
	//char* getPFirstName() { return Person::FirstName; }
	//char* getPLastName() { return Person::LastName; }
	//char* getPAddress() { return Person::Address; }
	//int getPDateOfBirth() { return Person::DateOfBirth; }

	///// Getters for Employee portion
	//char* getEFirstName() { return Employee::FirstName; }
	//char* getELastName() { return Employee::LastName; }
	//char* getEAddress() { return Employee::Address; }
	//int getEDateOfBirth() { return Employee::DateOfBirth; }
	//int getEEmpID() { return Employee::EmpID; }
	//int getESalary() { return Employee::Salary; }
	//char* getEOrganization() { return Employee::Organization; }
	//char* getEDesignation() { return Employee::Designation; }

	///// Getters for Student portion
	//char* getSFirstName() { return Student::FirstName; }
	//char* getSLastName() { return Student::LastName; }
	//char* getSAddress() { return Student::Address; }
	//int getSDateOfBirth() { return Student::DateOfBirth; }
	//int getSStudentID() { return Student::StudentID; }
	//double getSCGPA() { return Student::cgpa; }
	//char* getSDepartment() { return Student::Department; }
	//int getSCurSem() { return Student::CurrentSemester; }

	///// Patient portion
	//char* getpFirstName() { return Patient::FirstName; }
	//char* getpLastName() { return Patient::LastName; }
	//char* getpAddress() { return Patient::Address; }
	//int getpDateOfBirth() { return Patient::DateOfBirth; }
	//int getPatientID() { return Patient::PatientID; }
	//float getPTestResult() { return Patient::TestResult; }
	//char* getPHospitalName() { return Patient::HospitalName; }
	//char* getPDiagnostics() { return Patient::Diagnostics; }

	//// Setters

	///// Setters for Person Portion
	////void setPFirstName(char* FName) {Person}
	//void setPDateOfBirth(int Birth) { Person::DateOfBirth = Birth; }

};

