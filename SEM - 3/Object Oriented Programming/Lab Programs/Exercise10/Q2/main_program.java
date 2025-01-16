package Exercise10.Q2;

import java.io.File;
import java.util.Date;
import java.util.Calendar;

public class main_program {
    
    public static void main(String[] args) {
        
        String filePath = "src/Exercise10/Data/text.txt";
        
        File file = new File(filePath);
        
        try {
            
            if (file.exists()){
    
                // Returns milliseconds since the epoch. (January 1, 1970, 00:00:00 GMT)
                long lastModified = file.lastModified();
        
                // Creates a date object for the given milliseconds since January 1, 1970, 00:00:00 GMT.
                Date date = new Date(lastModified);
        
                System.out.println("Date: " + date.toString());
                
                Calendar calendar = Calendar.getInstance();
                calendar.setTime(date);
        
                int year = calendar.get(Calendar.YEAR);
                int month = calendar.get(Calendar.MONTH) + 1;
                int day = calendar.get(Calendar.DAY_OF_MONTH);
                int hour = calendar.get(Calendar.HOUR_OF_DAY);
                int minute = calendar.get(Calendar.MINUTE);
                int second = calendar.get(Calendar.SECOND);
                
                System.out.printf("Last modified date and time: %02d-%02d-%04d %02d:%02d:%02d%n", 
                                    day, month, year, hour, minute, second);
            }
    
            else
                System.out.println("File Does Not Exist !");
        }
        catch (Exception exception){

            System.out.println("Error: " + exception.getMessage());
            System.out.println("Error Type" + exception.getClass().getName());
        }

    }
}
