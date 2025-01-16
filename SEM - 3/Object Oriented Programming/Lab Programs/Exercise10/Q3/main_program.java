package Exercise10.Q3;

import java.io.File;
import java.util.Scanner;

public class main_program {
    
    public static void main(String[] args) {

        Scanner scanner = new Scanner(System.in);
        String filePath = "src/Exercise10/Data/text.txt";
        String newFilePath = "";

        File file = new File(filePath);

        System.out.print("Enter the new name for the file with extention: ");
        String newFileName = scanner.nextLine();
        
        String[] filePathSplit = filePath.split("/");
        
        for (int i = 0; i < filePathSplit.length - 1; i++) newFilePath += filePathSplit[i] + "/";
        
        newFilePath += newFileName;
        
        File newFile = new File(newFilePath);

        if (file.exists()){

            if (file.renameTo(newFile))
                System.out.println("Renamed Successfully: " + newFile.getName());

            else
                System.out.println("Error. Can't Rename the file.");
        }

        else
            System.out.println("File Does Not Exist !");

        scanner.close();
    }
}
