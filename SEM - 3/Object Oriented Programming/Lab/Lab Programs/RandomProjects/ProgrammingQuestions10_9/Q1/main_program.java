package RandomProjects.ProgrammingQuestions10_9.Q1;

import java.util.Scanner;

public class main_program {

    public static void main(String[] args) {

        String string = "";
        int noOfChars = 5;

        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter: ");
        String temp = scanner.nextLine();

        if (temp.length() <= noOfChars)
            string = temp;

        else {
            for (int i = 0; i < noOfChars; i++)
                string = string.concat(String.valueOf(temp.charAt(i)));
        }

        System.out.println("Got: " + string);
        System.out.println("Upper Case: " + string.toUpperCase());

        scanner.close();
    }
}
