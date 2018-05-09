#pragma once

class Person
{
public:
	Person(int db) {
		this->DateOfBirth = db;
	}
	int DateOfBirth;
	char* FirstName;
	char* LastName;
	char* Address;
};

