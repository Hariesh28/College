package Exercise8.Q1;

public class Hall2 implements Hall {

    private int employeeID;
    private int age;

    Hall2(int employeeID, int age) throws CustomError {

        if (employeeID % 2 == 1 && age > 30) {

            this.employeeID = employeeID;
            this.age = age;

            System.out.println("Welcome to the Party -> Hall 2");
        }

        else throw new CustomError("You are not allowed in hall 2");

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
