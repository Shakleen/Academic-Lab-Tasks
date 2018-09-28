package EmployeeRecords;

public class Employee {
    private static int noOfEmployees = 0;
    private String name;
    private int ID;
    private String dateOfBirth;
    private String email;
    private String contact;
    private String number;
    private int salary;
    private int contractDays;

    public Employee(String name, String dateOfBirth, String email, String contact, String number, int salary, int contractDays) {
        this.name = name;
        this.ID = ++noOfEmployees;
        this.dateOfBirth = dateOfBirth;
        this.email = email;
        this.contact = contact;
        this.number = number;
        this.salary = salary;
        this.contractDays = contractDays;
    }

    public void ShowInfo(boolean level1, boolean level2, boolean level3){
        ShowInfo(level1, level2);
        System.out.println("Salary : " + this.salary);
        System.out.println("Contract days : " + this.contractDays);
    }

    public void ShowInfo(boolean level1, boolean level2){
        ShowInfo(level1);
        System.out.println("Email : " + this.email);
        System.out.println("Number : " + this.number);
        System.out.println("Contact : " + this.contact);
    }

    public void ShowInfo(boolean level1){

        System.out.println("Name : " + this.name);
        System.out.println("ID : " + this.ID);
        System.out.println("Date of birth : " + this.dateOfBirth);
    }
}
