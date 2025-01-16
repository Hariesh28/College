package Exercise11.Q3;

import java.util.ArrayList;
import java.util.List;
import java.util.Random;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {

        Bank account;
        RandomGenerator rand;
        List<Thread> threads;
        Scanner scanner;

        String transactionType;
        double amount;
        int transactionCount, initialBalance;
        long waitTime;

        {
            scanner = new Scanner(System.in);
            rand = new RandomGenerator();
            threads = new ArrayList<>();
        }

        System.out.print("Enter Initial Balance: ");
        initialBalance = scanner.nextInt();

        System.out.print("Enter No Of Transactions: ");
        transactionCount = scanner.nextInt();

        System.out.print("Enter Waiting Time In Seconds: ");
        waitTime = scanner.nextLong() * 1000;

        {
            account = new Bank(initialBalance, waitTime);
        }

        for (int i = 1; i < transactionCount + 1; i++){

            transactionType = rand.deposit_withdraw();
            amount = rand.getAmount();

            System.out.println("Starting Transaction " + i + " " + transactionType + " " + "Amount: " + amount);

            createAndStartThread(account, amount,  transactionType + " id:" + i, threads, transactionType);
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

        if (account.getFailedTransactions().isEmpty()) {

            System.out.println("No Failed Transactions.");
        }
        else {

            System.out.println("Failed Transactions:");
            account.getFailedTransactions().forEach(Main::log);
        }

        System.out.println("\nFinal Account Balance: " + account.getAmount());
    }

    private static void createAndStartThread (Bank bank, double amount, String name, List<Thread> threads, String type){

        Thread transactionThread;

        if (type.equals("deposit")){
            transactionThread = new DepositTask(bank, amount, name);

            // If current balance is low, prioritize deposits to avoid failed withdrawals
            if (bank.getAmount() < 1000)
                transactionThread.setPriority(Thread.MAX_PRIORITY);

            else
                transactionThread.setPriority(Thread.NORM_PRIORITY);
        }

        else {

            transactionThread = new WithdrawTask(bank, amount, name);

            // If balance is sufficient, prioritize withdrawals to avoid long wait times
            if (bank.getAmount() >= amount)
                transactionThread.setPriority(Thread.MAX_PRIORITY);

            else
                transactionThread.setPriority(Thread.NORM_PRIORITY);
        }

        transactionThread.start();
        threads.add(transactionThread);
    }

    private static void log (String message){

        System.out.println("[" + java.time.LocalTime.now() + "] " + message);
    }
}

class Bank {

    private double amount;
    private final long waitTime;
    private final List<String> failedTransactions;

    {
        failedTransactions = new ArrayList<>();
    }

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

    public synchronized void withdraw (double amount) throws InterruptedException, WithdrawalTimeoutException{

        long startTime = System.currentTimeMillis();

        while (amount > this.amount){

            long elapsedTime = System.currentTimeMillis() - startTime;
            long remainingTime = waitTime - elapsedTime;

            if (remainingTime <= 0){

                String errorMessage = "Timeout waiting for deposits for withdrawal of amount: " + amount;

                failedTransactions.add(Thread.currentThread().getName());

                throw new WithdrawalTimeoutException(errorMessage);
            }

            System.out.println("Insufficient Funds! Waiting For Deposits...");
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

    public List<String> getFailedTransactions(){
        return failedTransactions;
    }
}

class DepositTask extends Thread {

    private final Bank account;
    private final double amount;

    public DepositTask(Bank account, double amount, String name){

        super(name);
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

    public WithdrawTask(Bank account, double amount, String name){

        super(name);
        this.account = account;
        this.amount = amount;
    }

    @Override
    public void run (){

        try {

            account.withdraw(amount);

            // Withdrawing Delay
            Thread.sleep(2000);

        } catch (InterruptedException | WithdrawalTimeoutException exception){

            System.out.println("Withdrawal failed: " + exception.getMessage());
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

class WithdrawalTimeoutException extends Exception {
    public WithdrawalTimeoutException(String message) {
        super(message);
    }
}
