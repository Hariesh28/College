package Exercise11.Q3_V2;

import java.util.ArrayList;
import java.util.List;
import java.util.Random;
import java.util.Scanner;

class Bank {

    private double amount;
    private final long waitTime;

    public Bank(){

        this.amount = 0.0;
        waitTime = 5000;
    }

    public Bank(double amount, long waitTime){

        this.amount = amount;
        this.waitTime = waitTime;
    }

    public Bank(int amount, long waitTime){

        this((double) amount, waitTime);
    }

    public synchronized void deposit (double amount){

        this.amount += amount;

        System.out.println("Deposited: " + amount);
        this.printBalance();

        notifyAll();
    }

    public synchronized void withdraw (double amount) throws InterruptedException{

        long startTime = System.currentTimeMillis();

        while (amount > this.amount){

            long elapsedTime = System.currentTimeMillis() - startTime;
            long remainingTime = waitTime - elapsedTime;

            if (remainingTime <= 0){

                System.out.println("Transaction Failed: Timout Waiting For Deposits... Amount: " + amount);
                Thread.currentThread().interrupt();
                return;
            }

            System.out.println("Insufficient Amount In Account !!! Waiting For Deposits...");
            wait(remainingTime);
        }

        this.amount -= amount;
        System.out.println("Withdrawn: " + amount);
        this.printBalance();
    }

    public synchronized double getAmount(){

        return amount;
    }

    private void printBalance(){

        System.out.println("Balance: " + Math.round(this.amount * 100.0) / 100.0);
    }
}

class DepositTask extends Thread {

    private final Bank account;
    private final double amount;

    public DepositTask(Bank account, double amount){

        this.account = account;
        this.amount = amount;
    }

    @Override
    public void run (){

        account.deposit(amount);

        try {

            // Depositing Delay
            Thread.sleep(1000);

        } catch (InterruptedException exception){

            Thread.currentThread().interrupt();
        }
    }
}


class WithdrawTask extends Thread {

    private final Bank account;
    private final double amount;

    public WithdrawTask(Bank account, double amount){

        this.account = account;
        this.amount = amount;
    }

    @Override
    public void run (){

        try {

            account.withdraw(amount);

            // Withdrawing Delay
            Thread.sleep(2000);

        } catch (InterruptedException exception){

            Thread.currentThread().interrupt();
        }
    }
}

class RandomGenerator {

    private int min_amount;
    private int max_amount;
    private final Random random;

    {
        min_amount = 200;
        max_amount = 500;
        random = new Random();
    }

    public RandomGenerator(){

    }

    public RandomGenerator(int min_amount, int max_amount){
        this.min_amount = min_amount;
        this.max_amount = max_amount;
    }

    public String deposit_withdraw(){

        return (random.nextBoolean()) ? "deposit" : "withdraw";
    }

    public double getAmount(){

        double amount = min_amount + random.nextDouble() * (max_amount - min_amount);

        return Math.round(amount * 100.0) / 100.0;
    }

    public int getMin_amount() {
        return min_amount;
    }

    public void setMin_amount(int min_amount) {
        this.min_amount = min_amount;
    }

    public int getMax_amount() {
        return max_amount;
    }

    public void setMax_amount(int max_amount) {
        this.max_amount = max_amount;
    }
}

public class Main {

    public static void main(String[] args) {

        Bank account;
        RandomGenerator rand;
        List<Thread> threads;
        Scanner scanner;

        String choice;
        double amount;
        int noOfTransactions, initialBalance;
        long waitTime;

        {
            scanner = new Scanner(System.in);
            rand = new RandomGenerator();
            threads = new ArrayList<Thread>();
        }

        System.out.print("Enter Initial Balance: ");
        initialBalance = scanner.nextInt();

        System.out.print("Enter No Of Transactions: ");
        noOfTransactions = scanner.nextInt();

        System.out.print("Enter Waiting Time In Seconds: ");
        waitTime = scanner.nextLong() * 1000;

        {
            account = new Bank(initialBalance, waitTime);
        }

        for (int i = 0; i < noOfTransactions; i++){

            choice = rand.deposit_withdraw();
            amount = rand.getAmount();

            System.out.println("Starting Transaction " + i + " " + choice + " " + "Amount: " + amount);

            if (choice.equals("deposit")){

                Thread depositThread = new DepositTask(account, amount);
                depositThread.start();
                threads.add(depositThread);
            }

            else if (choice.equals("withdraw")){

                Thread withdrawThread = new WithdrawTask(account, amount);
                withdrawThread.start();
                threads.add(withdrawThread);
            }
        }

        // Wait for all the threads to complete
        for (Thread thread : threads){

            try {

                thread.join();

            } catch (InterruptedException e) {
                System.out.println(e.getMessage());
                Thread.currentThread().interrupt();
            }
        }

        System.out.println("Final Account Balance: " + account.getAmount());
    }
}
