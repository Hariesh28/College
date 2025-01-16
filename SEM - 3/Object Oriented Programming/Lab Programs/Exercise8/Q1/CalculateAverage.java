package Exercise8.Q1;

public class CalculateAverage {

    public static void CalculateAverageAge(Hall[] halls, boolean all) {

        double[] average = {0, 0, 0};
        int[] count = {0, 0, 0};
        int[] sum = {0, 0, 0};

        Hall lastHall = null;

        for (Hall hall : halls) {

            if(hall != null) {

                if (hall instanceof Hall1){

                    sum[0] += hall.getAge();
                    count[0]++;
                }

                if (hall instanceof Hall2){

                    sum[1] += hall.getAge();
                    count[1]++;
                }

                if (hall instanceof Hall3){

                    sum[2] += hall.getAge();
                    count[2]++;
                }

                lastHall = hall;
            }
        }

        for (int i = 0; i < 3; i++) {

            if (count[i] != 0) average[i] = (double) sum[i] / count[i];
        }

        if (all){

            for (int i = 0; i < 3; i++) System.out.println("Average of Hall" + (i+1) + ": " + average[i]);
        }

        else{

            if (lastHall != null) {

                if (lastHall instanceof Hall1) System.out.println("Average of Hall1: " + average[0]);
                else if (lastHall instanceof Hall2) System.out.println("Average of Hall2: " + average[1]);
                else System.out.println("Average of Hall3: " + average[2]);
            }

            else System.out.println("Unable to find any Hall");
        }
    }
}
