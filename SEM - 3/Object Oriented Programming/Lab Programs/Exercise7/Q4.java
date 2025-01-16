package Exercise7;

import java.util.Scanner;

public class Q4{

    public static void main(String[] args) {

        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter numerator: ");
        int numerator = scanner.nextInt();
        scanner.nextLine();

        System.out.print("Enter divisor: ");
        int divisor = scanner.nextInt();
        scanner.nextLine();

        scanner.close();

        try {

            performDivision(numerator, divisor);
        } catch (ArithmeticException e) {
            
            System.out.println("Caught an exception: " + e.getMessage());
        } finally {
            
            System.out.println("Finally block executed.");
        }
    }

    public static void performDivision(int numerator, int divisor) throws ArithmeticException{
        
        if (divisor == 0) {

            throw new ArithmeticException("Cannot divide by zero");
        }

        int result = numerator / divisor;
        System.out.println("Result of division: " + result);
    }
}
