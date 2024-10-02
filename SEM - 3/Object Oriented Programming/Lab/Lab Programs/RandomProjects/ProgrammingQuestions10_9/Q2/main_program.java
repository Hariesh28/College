package RandomProjects.ProgrammingQuestions10_9.Q2;

public class main_program {

    public static void main(String[] args) {

        int[] a = {8, 4, 1, 5, 3, 0, 6, 10, 9, 7};
        int n = a.length;
        int maximum;

        if (n == 1){

            maximum = a[0];
            System.out.println("maximum is " + maximum);
            return;
        }

        else maximum = a[0];

        for (int i = 0; i < n-1; i++){

            if (a[i] > maximum) maximum = a[i];
        }

        if (a[n-1] > maximum) maximum = a[n-1];

        System.out.println("Maximum is: " + maximum);
    }
}
