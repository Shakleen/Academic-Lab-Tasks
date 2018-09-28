package com.company;

import EmployeeRecords.Employee;

public class Main {

    public static void main(String[] args) {
        Employee obj = new Employee("Ishfar", "30/04/1997",
                "shakleenishfar@gmil.com", "Malibagh",
                "+8801830582716", 29000, 365);

        Employee obj2 = new Employee("Ishrak", "31/01/1996",
                "ishrak@gmil.com", "Mirpur",
                "+88009128401924", 51000, 365);

        obj2.ShowInfo(true, true, true);
    }
}
