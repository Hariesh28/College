package Exercise6;
import java.util.Scanner;

public class Q1 {
    
    public static void main(String[] args) {
        
        Scanner scanner = new Scanner(System.in);
    
        System.out.print("Enter the string: ");
        String word = scanner.nextLine();

        System.out.print("Enter the index: ");
        int index = scanner.nextInt();
        scanner.nextLine();

        if(index >= word.length() || index < 0)
            System.out.println("Invalid Index");

        else
            System.out.println("Character at index " + index + " is " + word.charAt(index));

        scanner.close();
    }
}
