package RandomProjects.String_Array_Basic_Sort_Thingy;

import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

public class main_program {

    public static void main(String[] args) {

        Scanner scanner = new Scanner(System.in);
        ArrayList<String> list = new ArrayList<String>();

        for (int i = 0; i < 5; i++) {

            System.out.print("Enter word: ");
            String word = scanner.nextLine();

            list.add(word);
        }

        System.out.print("Original list: ");
        for (String s : list) {
            System.out.print(s + " ");
        }

//        list.sort(String.CASE_INSENSITIVE_ORDER);

        Collections.sort(list);

        System.out.print("\nSorted list: ");
        for (String s : list) {
            System.out.print(s + " ");
        }
    }
}
