package Exercise7;

import java.util.Scanner;

public class Q1 {

    public static void main(String[] args) {

        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter size: ");
        int size = scanner.nextInt();
        scanner.nextLine();

        try {

            int[] Array = new int[size];
            System.out.println("Successfully Created !\nSize: " + Array.length);
        }

        catch(NegativeArraySizeException exception){

            System.out.println("Error !\nReceived: " + exception.getMessage());
        }

        scanner.close();
    }
}
