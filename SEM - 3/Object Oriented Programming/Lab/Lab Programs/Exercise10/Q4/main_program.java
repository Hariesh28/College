package Exercise10.Q4;

import java.io.File;
import java.util.Scanner;

public class main_program {
    
    public static void main(String[] args) {
        
        Scanner scanner = new Scanner(System.in);
        String directoryPath = "src/Exercise10/Data/";

        System.out.print("Enter the name of the directory: ");
        String directoryName = scanner.nextLine();

        directoryPath += directoryName;

        File directory = new File(directoryPath);

        if (directory.mkdir())
            System.out.println("Directory created successfully: " + directory.getAbsolutePath());

        else {

            if (directory.exists())
                System.out.println("Directory already exists: " + directory.getAbsolutePath());

            else
                System.out.println("Failed to create the directory");
        }

        scanner.close();
    }
}
