package Exercise3;
import java.util.Scanner;

public class main_program {

    public static void main(String[] args) {

        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter the Employee Name: ");
        String empName = scanner.nextLine();

        System.out.print("Enter the Employee ID: ");
        int empId = scanner.nextInt();
        scanner.nextLine();

        System.out.print("Enter the Address: ");
        String address = scanner.nextLine();

        System.out.print("Enter the Mail ID: ");
        String mailId = scanner.nextLine();

        System.out.print("Enter the Mobile No: ");
        long mobileNo = scanner.nextLong();
        scanner.nextLine();

        System.out.print("Enter the Basic Pay: ");
        double basicPay = scanner.nextDouble();

        System.out.println("Enter the type of Employee: ");
        System.out.println("1. Programmer");
        System.out.println("2. Assistant Professor");
        System.out.println("3. Associate Professor");
        System.out.println("4. Professor");
        System.out.print("Enter: ");
        int type = scanner.nextInt();
        scanner.nextLine();

        switch (type) {

            case 1:
                Programmer programmer = new Programmer(empId,empName, address, mailId, mobileNo, basicPay);
                programmer.generatePaySlip();
                break;

            case 2:
                Assistant_Professor assistant_Professor = new Assistant_Professor(empId,empName, address, mailId, mobileNo, basicPay);
                assistant_Professor.generatePaySlip();
                break;

            case 3:
                Associate_Professor associate_Professor = new Associate_Professor(empId, empName, address, mailId, mobileNo, basicPay);
                associate_Professor.generatePaySlip();
                break;

            case 4:
                Professor professor = new Professor(empId, empName, address, mailId, mobileNo, basicPay);
                professor.generatePaySlip();
                break;

            default:
                System.out.println("Invalid type of Employee");
                break;
        }

        scanner.close();
    }
}
