package Exercise7;
import java.util.Scanner;

class CustomError extends Exception{

    public CustomError(String message){

        super(message);
    }
}

public class Q2 {
    

    public static void main(String[] args) {
        
        Scanner scanner = new Scanner(System.in); 

        System.out.print("Enter the age: ");
        int age = scanner.nextInt();
        scanner.nextLine();

        try{

            checkVotingAge(age);
        }

        catch(CustomError error){

            System.out.println(error.getMessage());
        }

        scanner.close();
    }

    public static void checkVotingAge(int age) throws CustomError{
        
        if (age < 18){

            throw new CustomError("Not Eligible To Vote");
        }

        else
            System.out.println("Eligible To Vote");
    }
}
