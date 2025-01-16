package Exercise8.Q2;

public class Voting {

    public static void validAgeForVoting(String currentData, String dateOfBirth) throws InvalidAgeForVoting{

        String[] dobParts = dateOfBirth.split("-");
        String[] dateParts = currentData.split("-");

        int birthDay = Integer.parseInt(dobParts[0]);
        int birthMonth = Integer.parseInt(dobParts[1]);
        int birthYear = Integer.parseInt(dobParts[2]);

        int currentDay = Integer.parseInt(dateParts[0]);
        int currentMonth = Integer.parseInt(dateParts[1]);
        int currentYear = Integer.parseInt(dateParts[2]);

        int age = currentYear - birthYear;

        if (birthMonth > currentMonth || (birthMonth == currentMonth && birthDay > currentDay)) age--;

        if (age >= 18) System.out.println("Eligible for voting");
        else throw new InvalidAgeForVoting("Not eligible for voting");
    }
}
