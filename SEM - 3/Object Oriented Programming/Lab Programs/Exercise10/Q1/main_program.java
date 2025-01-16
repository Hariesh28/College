package Exercise10.Q1;

import java.io.File;

public class main_program {
    
    public static void main(String[] args) {
        
        String filePath = "src/Exercise10/Data/text.txt";
    
        File file = new File(filePath);
    
        try {
    
            if (file.exists())
                System.out.println("File Found: " + file.getAbsolutePath());
    
            else
                System.out.println("File NOT Found: " + file.getAbsolutePath());

        } catch (Exception exception){

            System.out.println("Error: " + exception.getMessage());
            System.out.println("Error Type" + exception.getClass().getName());
        }
    }
}
