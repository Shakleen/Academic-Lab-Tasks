public class Employee
{
    public int ID;
    public String Name;
    public String Dept;
    public String Desig;
    public int PhoneNo;
    public String Address;
    public String DOB;
    public double InitBasic;
    public double Increments;
    public double TotalSalary;
    
    private double TotalBasic;

    public Employee()
    {
        ID = PhoneNo = -1;
        Name = "John Doe";
        Dept = Desig = Address = DOB = "N/A";
        InitBasic = Increments = TotalSalary = 0.0d;
    }

    public Employee(int ID, String Name, String Dept, String Desig, int Phoneno, String Address, String DOB, double InitBasic, double Increments)
    {
        this->ID = ID;
        this->Name = Name;
        this->Dept = Dept;
        this->Desig = Desig;
        this->PhoneNo = PhoneNo;
        this->Address = Address;
        this->DOB = DOB;
        this->InitBasic = InitBasic;
        this->Increments = Increments;

        TotalBasic = (InitBasic + (Increments * 50d));
        TotalSalary = TotalBasic + TotalBasic * 0.45d;
    }

    public void getSalary()
    {
        System.out.println("ID of employee = " + this->ID);
        System.out.println("Name of employee = " + this->Name);
        System.out.println("Salary of employee = " + this->TotalSalary);
    }
}