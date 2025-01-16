package Exercise7;

public class Q3 {

    public static void main(String[] args) {
        
        String[] inputs = {"100", "abc", "12.34", null};

        for (String input : inputs) {

            try {
        
                int number = Integer.parseInt(input);

                int result = number / 0;

                System.out.println("Result of division: " + result);

            } catch (NumberFormatException e) {
        
                System.out.println("Error: Invalid number format. " + e.getMessage());

            } catch (ArithmeticException e) {
        
                System.out.println("Error: Arithmetic exception. " + e.getMessage());

            } catch (NullPointerException e) {
        
                System.out.println("Error: Null pointer exception. " + e.getMessage());

            } catch (Exception e) {
        
                System.out.println("Unexpected error: " + e.getMessage());
            }
        }
    }
}
