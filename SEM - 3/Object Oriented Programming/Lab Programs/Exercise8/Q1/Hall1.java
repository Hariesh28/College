package Exercise8.Q1;

public class Hall1 implements Hall {

    private int employeeID;
    private int age;

    Hall1(int employeeID, int age) throws CustomError {

        if (employeeID % 2 == 0 && age < 30) {

            this.employeeID = employeeID;
            this.age = age;

            System.out.println("Welcome to the Party -> Hall 1");
        }

        else throw new CustomError("You are not allowed in hall 1");

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
