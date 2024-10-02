package Exercise6;
import java.util.LinkedList;
import java.util.Scanner;

public class Q3 {
    
    public static void main(String[] args) {
        
        LinkedList<String> list = new LinkedList<>();
        Scanner scanner = new Scanner(System.in);

        while(true){

            printMenu();
            int choice = scanner.nextInt();
            scanner.nextLine();

            switch(choice){

                case 1:
                    System.out.print("Enter the value: ");
                    String data = scanner.nextLine();

                    list.add(data);
                    break;

                case 2:
                    System.out.println("Removed: " + list.remove());
                    break;

                case 3:
                    for(String element: list) System.out.print(element + " ");
                    System.out.println();
                    break;

                case 4:
                    System.out.println(list);
                    break;

                case 5:
                    System.out.println("Exited !!");
                    scanner.close();
                    return;

                default:
                    System.out.println("Invalid Choice");
                    break;
            }
        }

    }

    public static void printMenu(){

        System.out.println("1. Insert");
        System.out.println("2. Remove");
        System.out.println("3. Display");
        System.out.println("4. Print");
        System.out.println("5. Exit");
        System.out.print("Enter: ");
    }
}
