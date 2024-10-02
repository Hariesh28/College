package Exercise9.Q2;

import java.util.Random;
import java.util.Scanner;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.io.FileNotFoundException;

public class main_program {

    public static void main(String[] args) {

        Random random = new Random();
        String[] names = {"Liam", "Olivia","Noah", "Emma", "Oliver",  "Charlotte", "James", "Amelia", "Elijah", "Sophia"};
        String data, studentName;
        int marks;
    
        try {

            File marksFile = new File("src\\Exercise9\\Q2\\marks.txt");
            FileWriter marksFileWriter = new FileWriter(marksFile);

            marksFile.createNewFile();

            for (String name : names) {
                
                marks = random.nextInt(100) + 1;
                data = name + " " + marks + "\n";

                marksFileWriter.write(data);
            }

            marksFileWriter.close();

        } catch (IOException e){

            System.out.println("Error: " + e.getMessage());
        }

        try {

            File marksFile = new File("src\\Exercise9\\Q2\\marks.txt");
            Scanner readMarks = new Scanner(marksFile);

            File bestPerformance = new File("src\\Exercise9\\Q2\\best performace.txt");
            bestPerformance.createNewFile();
            FileWriter bestPerformanceWriter = new FileWriter(bestPerformance);

            File lowPerformance = new File("src\\Exercise9\\Q2\\low performace.txt");
            lowPerformance.createNewFile();
            FileWriter lowPerformanceWriter = new FileWriter(lowPerformance);

            while (readMarks.hasNextLine()){

                data = readMarks.nextLine();
                marks = Integer.parseInt(data.split(" ")[1]);
                studentName = data.split(" ")[0];
                
                if (marks >  90) bestPerformanceWriter.write(studentName + "\n");
                if (marks < 40) lowPerformanceWriter.write(studentName + "\n");
            }

            readMarks.close();
            bestPerformanceWriter.close();
            lowPerformanceWriter.close();

        } catch (FileNotFoundException e){

            System.out.println("Error: " + e.getMessage());
        
        } catch (IOException e){

            System.out.println("Error: " + e.getMessage());
        }
    }
}
