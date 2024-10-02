package Exercise2.main_program;

import Exercise2.converter.currency.currency_converter;
import Exercise2.converter.distance.distance_converter;
import Exercise2.converter.time.time_converter;

import java.util.Scanner;

public class main_program {

    public static void main(String[] args) {

        Scanner scanner = new Scanner(System.in);
        boolean exit = false;

        while (!exit) {

            System.out.println("Select conversion type:");
            System.out.println("1. Currency Converter");
            System.out.println("2. Distance Converter");
            System.out.println("3. Time Converter");
            System.out.println("4. Exit");
            System.out.print("Enter your choice: ");
            int choice = scanner.nextInt();

            switch (choice) {

                case 1:
                    System.out.println("Currency Converter:");
                    System.out.println("1. Dollar to INR");
                    System.out.println("2. INR to Dollar");
                    System.out.println("3. Euro to INR");
                    System.out.println("4. INR to Euro");
                    System.out.println("5. Yen to INR");
                    System.out.println("6. INR to Yen");

                    System.out.print("Enter your choice: ");
                    int currencyChoice = scanner.nextInt();

                    System.out.print("Enter amount to convert: ");
                    double amount = scanner.nextDouble();

                    double convertedAmount = 0;

                    switch (currencyChoice) {

                        case 1:
                            convertedAmount = currency_converter.dollar_to_inr(amount);
                            break;

                        case 2:
                            convertedAmount = currency_converter.inr_to_dollar(amount);
                            break;

                        case 3:
                            convertedAmount = currency_converter.euro_to_inr(amount);
                            break;

                        case 4:
                            convertedAmount = currency_converter.inr_to_euro(amount);
                            break;

                        case 5:
                            convertedAmount = currency_converter.yen_to_inr(amount);
                            break;

                        case 6:
                            convertedAmount = currency_converter.inr_to_yen(amount);
                            break;
                    }

                    System.out.println("Amount converted: " + convertedAmount);
                    break;

                case 2:
                    System.out.println("Distance Converter:");
                    System.out.println("1. Meter to KM");
                    System.out.println("2. KM to Meter");
                    System.out.println("3. Miles to KM");
                    System.out.println("4. KM to Miles");

                    System.out.print("Enter your choice: ");
                    int distanceChoice = scanner.nextInt();

                    System.out.print("Enter amount to convert: ");
                    double distance = scanner.nextDouble();
                    double convertedDistance = 0;

                    switch (distanceChoice) {

                        case 1:
                            convertedDistance = distance_converter.meter_to_km(distance);
                            break;

                        case 2:
                            convertedDistance = distance_converter.km_to_meter(distance);
                            break;

                        case 3:
                            convertedDistance = distance_converter.mile_to_km(distance);
                            break;

                        case 4:
                            convertedDistance = distance_converter.km_to_mile(distance);
                            break;
                    }

                    System.out.println("Distance converted: " + convertedDistance);
                    break;

                case 3:
                    System.out.println("Time Converter:");
                    System.out.println("1. Hour to Minute");
                    System.out.println("2. Minute to Hour");
                    System.out.println("3. Hour to Second");
                    System.out.println("4. Second to Hour");
                    System.out.println("5. Minute to Second");
                    System.out.println("6. Second to Minute");

                    System.out.print("Enter your choice: ");
                    int timeChoice = scanner.nextInt();

                    System.out.print("Enter amount to convert: ");
                    double time = scanner.nextDouble();
                    double convertedTime = 0;

                    switch (timeChoice) {

                        case 1:
                            convertedTime = time_converter.hour_to_minutes(time);
                            break;

                        case 2:
                            convertedTime = time_converter.minute_to_hour(time);
                            break;

                        case 3:
                            convertedTime = time_converter.hour_to_second(time);
                            break;

                        case 4:
                            convertedTime = time_converter.second_to_hour(time);
                            break;

                        case 5:
                            convertedTime = time_converter.minute_to_second(time);
                            break;

                        case 6:
                            convertedTime = time_converter.second_to_minute(time);
                            break;
                    }

                    System.out.println("Time converted: " + convertedTime);
                    break;

                case 4:
                    System.out.println("Exited !");
                    exit = true;
                    scanner.close();
                    break;

                default:
                    System.out.println("Invalid choice");
                    break;
            }
        }
    }
}
