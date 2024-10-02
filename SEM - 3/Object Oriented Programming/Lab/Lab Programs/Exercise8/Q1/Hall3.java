package Exercise8.Q1;

public class Hall3 implements Hall{

    int employeeID;
    int age;

    Hall3(int employeeID, int age) throws CustomError {

        if((employeeID % 2 == 0 && age < 30) || (employeeID % 2 == 1 && age > 30))
            System.out.println("You are not allowed in hall 3");

        else {

            this.employeeID = employeeID;
            this.age = age;

            System.out.println("Welcome to the Party -> Hall 3");
        }
    }

    @Override
    public int getAge() {
        return age;
    }

    @Override
    public int getEmployeeID() {
        return employeeID;
    }

    @Override
    public void setAge(int age) {
        this.age = age;
    }

    @Override
    public void setEmployeeID(int employeeID) {
        this.employeeID = employeeID;
    }
}
