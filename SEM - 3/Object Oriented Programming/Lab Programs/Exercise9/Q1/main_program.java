package Exercise9.Q1;

import java.util.Scanner;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.FileWriter;

public class main_program {

    public static void main(String[] args) {

        File validationFile = new File("src\\Exercise9\\Q1\\validation.txt");
        Scanner scanner = new Scanner(System.in);

        String userName, password, data, userNameCurrent, passwordCurrent;
        boolean found = false;

        String content = "";

        if (args.length < 3){

            System.out.println("Insufficient number of args");
            scanner.close();
            return;
        }

        userName = args[0];
        password = args[1];

        for (int i = 2; i < args.length; i++) content += args[i] + " ";

        try {

            Scanner readValidationFile = new Scanner(validationFile);

            while (readValidationFile.hasNextLine()){

                data = readValidationFile.nextLine();

                userNameCurrent = data.split(" ")[0];
                passwordCurrent = data.split(" ")[1];

                if (userNameCurrent.equals(userName) && passwordCurrent.equals(password)){

                    System.out.println("Found: " + userNameCurrent + passwordCurrent);
                    found = true;
                    break;
                }
            }

            readValidationFile.close();

        } catch (FileNotFoundException e){

            System.out.println("Error: " + e.getMessage());
        }

        if(!found) System.out.println("Access Denied");

        if(found){

            try {

                File secretFile = new File("src\\Exercise9\\Q1\\secret.txt");
                FileWriter secretFileWriter = new FileWriter("secret.txt");

                secretFile.createNewFile();

                secretFileWriter.write(content);
                System.out.println("Written Successfully");

                secretFileWriter.close();

            } catch (IOException e){

                System.out.println("Error: " + e.getMessage());
            }
        }

        scanner.close();
    }
}
