package Exercise5;
import java.util.ArrayList;
import java.util.Scanner;
import java.util.Collections;

class methods{


    public static void printMenu(){

        System.out.println("\n1. Append");
        System.out.println("2. Insert");
        System.out.println("3. Search");
        System.out.println("4. List all string starts with given letter");
        System.out.println("5. Sort the strings in ascending and descending order");
        System.out.println("6. Print the list");
        System.out.println("7. Exit");
        System.out.print("Enter: ");
    }

    public static void addElement(ArrayList<String> stringArrayList, String dataString){

        stringArrayList.add(dataString);
    }


    public static void insertElement(ArrayList<String> stringArrayList, String dataString, int index){

        stringArrayList.add(index, dataString);
    }

    public static int search(ArrayList<String> stringArrayList, String dataString){

        int index = 0;

        for (String stringElement : stringArrayList) {

            if(stringElement.equals(dataString)) return index;
            index++;
        }

        return -1;
    }

    public static void startsWithLetter(ArrayList<String> stringArrayList, String dataString){

        for (String stringElement : stringArrayList) {

            if(stringElement.startsWith(dataString)){

                System.out.println(stringElement);
            }
        }
    }

    public static ArrayList<String> sortStrings(ArrayList<String> stringArrayList, boolean ascending){

        ArrayList<String> newArrayList = new ArrayList<String>();
//        ArrayList<String> newArrayList = new ArrayList<String>(stringArrayList);

        for (String element: stringArrayList) newArrayList.add(element);

        if(ascending)
            Collections.sort(newArrayList);

        else
            Collections.sort(newArrayList, Collections.reverseOrder());

        return newArrayList;
    }

    public static void printList(ArrayList<String> stringArrayList){

        for (String iString : stringArrayList) {
            System.out.print(iString + " ");
        }
    }
}

public class main_program {

    static int choice;
    static String data;
    static int index;

    public static void main(String[] args){

        Scanner scanner = new Scanner(System.in);

        ArrayList<String> list = new ArrayList<String>();

        while (true) {

            methods.printMenu();
            choice = scanner.nextInt();
            scanner.nextLine();

            switch (choice) {

                case 1:
                    System.out.print("Enter the value: ");
                    data = scanner.nextLine();
                    methods.addElement(list, data);

                    break;

                case 2:
                    System.out.print("Enter the index: ");
                    index = scanner.nextInt();
                    scanner.nextLine();
                    System.out.print("Enter the value: ");
                    data = scanner.nextLine();
                    methods.insertElement(list, data, index);

                    break;

                case 3:
                    System.out.print("Enter the value: ");
                    data = scanner.nextLine();
                    int result = methods.search(list, data);
                    System.out.print("Found at: " + result);
                    break;

                case 4:
                    System.out.print("Enter the value: ");
                    data = scanner.nextLine();
                    methods.startsWithLetter(list, data);
                    break;

                case 5:
                    System.out.println("1. Ascending");
                    System.out.println("2. Descending");
                    System.out.print("Enter: ");
                    int choice2 = scanner.nextInt();

                    if (choice2 == 1){

                        ArrayList<String> newArray = new ArrayList<>();
                        newArray = methods.sortStrings(list, true);
                        System.out.print("Sorted Array: ");
                        methods.printList(newArray);
                    }

                    else if(choice2 == 2){

                        ArrayList<String> newArray = new ArrayList<>();
                        newArray = methods.sortStrings(list, false);
                        System.out.print("Sorted Array: ");
                        methods.printList(newArray);
                    }

                    else
                        System.out.println("Invalid Choice");

                    break;

                case 6:
                    for (String iString : list) {
                        System.out.print(iString + " ");
                    }
                    break;

                case 7:
                    System.out.println("Exited !");
                    scanner.close();
                    return;

                default:
                    System.out.println("Invalid Choice");
                    break;
            }
        }
    }
}