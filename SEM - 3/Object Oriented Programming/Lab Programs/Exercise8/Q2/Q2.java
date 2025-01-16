package Exercise8.Q2;

import java.util.Scanner;

public class Q2 {

    public static void main(String[] args) throws InvalidAgeForVoting {

        Scanner scanner = new Scanner(System.in);

        System.out.println("Enter the date in the format DD-MM-YYYY: ");

        System.out.print("Enter current date: ");
        String curDate = scanner.nextLine();

        System.out.print("Enter date of birth: ");
        String birthDate = scanner.nextLine();

        try {

            Voting.validAgeForVoting(curDate, birthDate);
        } catch (InvalidAgeForVoting e) {

            System.out.println(e.getMessage());
        }

        scanner.close();
    }
}
