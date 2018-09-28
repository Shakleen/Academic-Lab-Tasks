public class Main
{
    public static void main (String args[]){
        Employee E1 = new Employee(),
                 E2 = new Employee(1, "Ishrak", "CSE", "BOSS", 101, "GGPUR", 10000, 100);
        
        E1.getSalary();

        E2.getSalary();
    }
}