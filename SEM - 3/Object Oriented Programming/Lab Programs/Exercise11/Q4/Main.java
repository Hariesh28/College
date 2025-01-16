package Exercise11.Q4;

import java.util.ArrayList;
import java.util.List;

public class Main {

    public static void main(String[] args) {

        ArrayList<Integer> list = new ArrayList<>();

        for (int i = 0; i < 21; i++) list.add(i);

        myClass.myMethod(list);
    }
}

class myClass {

    public static <T extends Number> void myMethod(List<T> numbers) {

        double oddSum, evenSum;

        {
            oddSum = 0;
            evenSum = 0;
        }

        for (T number: numbers){

            if (number.intValue() % 2 == 0) evenSum += number.doubleValue();
            else oddSum += number.doubleValue();
        }

        System.out.println("Odd Number Sum: " + oddSum);
        System.out.println("Even Number Sum: " + evenSum);
    }
}