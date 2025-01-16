package Exercise6;
import java.util.Scanner;

public class Q2 {
    
    private static final char invalid_char = '*';

    public static boolean kAnagrams(String word1, String word2, int k){

        if(word1.length() != word2.length()) return false;
        
        for(int i = 0; i < word1.length(); i++){
            
            for(int j = 0; j < word2.length(); j++){

                    if(word1.charAt(i) == word2.charAt(j)){

                        word1 = word1.substring(0, i) + invalid_char + word1.substring(i+1);
                        word2 = word2.substring(0, j) + invalid_char + word2.substring(j+1);
                    }
            }
        }

        int count = 0;

        for(int i = 0; i < word1.length(); i++){

            if(word1.charAt(i) != invalid_char) count++;
        }

        return count <= k;
    }

    public static void main(String[] args) {
        
        Scanner scanner = new Scanner(System.in);
        
        System.out.print("Enter the word 1:" );
        String word1 = scanner.nextLine();
        
        System.out.print("Enter the word 2: ");
        String word2 = scanner.nextLine();

        System.out.print("Enter the value of k: ");
        int k = scanner.nextInt();
        scanner.nextLine();

        System.out.println(kAnagrams(word1, word2, k));

        scanner.close();
    }
}
