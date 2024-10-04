package Exercise10.Q5;

import java.io.File;

public class main_program {
    
    public static void main(String[] args) {
        
        String filePath = "src/Exercise10/Data/text.txt";
    
        File file = new File(filePath);

        if (file.exists()){

            if (file.canRead())
                System.out.println("The file can be read: " + file.getName());
            
            else
                System.out.println("The file can NOT be read: " + file.getName());
        }

        else
            System.out.println("The file does NOT exist !");
    }
}
