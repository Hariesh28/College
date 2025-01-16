package Exercise8.Q1;

import java.util.Scanner;

public class Q1 {

    public static void main(String[] args) {

        Scanner scanner = new Scanner(System.in);

        Hall[] halls = new Hall[100];
        int halls_index = 0;

        int noOfEmployees;
        int employeeID;
        int age;

        System.out.print("Enter no. of employees: ");
        noOfEmployees = scanner.nextInt();
        scanner.nextLine();

        for (int i = 0; i < noOfEmployees; i++) {

            System.out.print("Enter employee ID: ");
            employeeID = scanner.nextInt();
            scanner.nextLine();

            System.out.print("Enter age: ");
            age = scanner.nextInt();
            scanner.nextLine();

            Hall hall1 = null;
            Hall hall2 = null;
            Hall hall3 = null;

            try {

                hall1 = new Hall1(employeeID, age);
            } catch (CustomError e){

                System.out.println(e.getMessage());
            }

            try {

                hall2 = new Hall2(employeeID, age);

            } catch (CustomError e){
                System.out.println(e.getMessage());
            }

            try {

                hall3 = new Hall3(employeeID, age);
            } catch (CustomError e){
                System.out.println(e.getMessage());
            }

            if (hall1 != null) halls[halls_index++] = hall1;
            else if (hall2 != null) halls[halls_index++] = hall2;
            else if (hall3 != null) halls[halls_index++] = hall3;

            try {

                CalculateAverage.CalculateAverageAge(halls, false);
            } catch (Exception e){
                System.out.println(e.getMessage());
            }
        }

        System.out.println("\nFinal Report: ");
        CalculateAverage.CalculateAverageAge(halls, true);
        scanner.close();
    }
}
