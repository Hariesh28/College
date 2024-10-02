package RandomProjects.practice3.q3;

import java.util.Scanner;

public class main_program {

    public static void main(String[] args) {

        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter the Employee Name: ");
        String empName = scanner.nextLine();

        System.out.print("Enter the Address: ");
        String address = scanner.nextLine();

        System.out.print("Enter the Basic Pay: ");
        double basicPay = scanner.nextDouble();

        System.out.println("Enter the type of Employee: ");
        System.out.println("1. Programmer");
        System.out.println("2. Developer");
        System.out.println("3. Manager");
        System.out.println("4. Exit");

        System.out.print("Enter: ");
        int type = scanner.nextInt();
        scanner.nextLine();

        switch (type) {

            case 1:
                Programmer programmer = new Programmer(empName, address, basicPay);
                programmer.generatePaySlip();
                break;

            case 2:
                Developer dev = new Developer(empName, address,  basicPay);
                dev.generatePaySlip();
                break;

            case 3:
                Manager man = new Manager( empName, address, basicPay);
                man.generatePaySlip();
                break;

            case 4:
                return;


            default:
                System.out.println("Invalid type of Employee");
                break;
        }

        scanner.close();
    }
}
