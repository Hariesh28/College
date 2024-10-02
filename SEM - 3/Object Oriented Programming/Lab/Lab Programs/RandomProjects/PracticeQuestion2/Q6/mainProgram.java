package RandomProjects.PracticeQuestion2.Q6;

import java.util.Scanner;

public class mainProgram {


    public static void main(String[] args) {

        Bank bank = new Bank();
        Scanner sc = new Scanner(System.in);

        while (true) {

            System.out.println("1. Add");
            System.out.println("2. Edit");
            System.out.println("3. Display");
            System.out.println("4. Exit");
            System.out.print("Enter your choice: ");

            int choice = sc.nextInt();
            sc.nextLine();

            int choice2;

            switch (choice) {

                case 1:
                    System.out.println("1. Savings Account");
                    System.out.println("2. Current Account");
                    System.out.print("Enter your choice: ");

                    choice2 = sc.nextInt();
                    sc.nextLine();

                    if (choice2 == 1) {

                        System.out.print("Enter Account number: ");
                        SavingsAccount savingsAccount = new SavingsAccount(sc.nextDouble());
                        sc.nextLine();

                        bank.addSavingsAccount(savingsAccount);
                        System.out.println("Account Added");
                    } else if (choice2 == 2) {

                        System.out.print("Enter Account number: ");
                        double accountNumber = sc.nextDouble();
                        sc.nextLine();

                        System.out.print("Enter Over Draft Amount: ");
                        double overdraftAmount = sc.nextDouble();
                        sc.nextLine();

                        CurrentAccount currentAccount = new CurrentAccount(accountNumber, overdraftAmount);
                        bank.addCurrentAccount(currentAccount);

                        System.out.println("Account Added");
                    } else
                        System.out.println("Invalid Choice");

                    break;

                case 2:
                    System.out.print("Enter Account number: ");
                    double accountNumber = sc.nextDouble();
                    sc.nextLine();

                    for (Account account: bank.accounts){

                        if (account != null){

                            if (account.getClass().getName().equals("RandomProjects.PracticeQuestion2.Q6.SavingsAccount")){

                                SavingsAccount savingsAccount = (SavingsAccount) account;

                                if (savingsAccount.getAccountNumber() == accountNumber){

                                    System.out.println("Account is a Savings Account");

                                    System.out.println("1. Edit Account Number");
                                    System.out.println("2. Deposit");
                                    System.out.println("3. Withdraw");
                                    System.out.print("Enter: ");

                                    int choice3 = sc.nextInt();
                                    sc.nextLine();

                                    if (choice3 == 1){

                                        System.out.println("Current Account number: " + savingsAccount.getAccountNumber());
                                        System.out.print("Enter Account number: ");
                                        double accountNo = sc.nextDouble();
                                        sc.nextLine();

                                        savingsAccount.setAccountNumber(accountNo);
                                        System.out.println("Account Edited");
                                    }

                                    else if (choice3 == 2){

                                        System.out.print("Deposit Amount: ");
                                        double depositAmount = sc.nextDouble();
                                        sc.nextLine();

                                        savingsAccount.deposit(depositAmount);
                                        System.out.println("Account Edited");
                                    }

                                    else if (choice3 == 3){

                                        System.out.print("Withdraw Amount: ");
                                        double withdrawAmount = sc.nextDouble();
                                        sc.nextLine();

                                        savingsAccount.withdraw(withdrawAmount);
                                        System.out.println("Account Edited");
                                    }

                                    else
                                        System.out.println("Invalid Choice");
                                }
                            }

                            else if (account.getClass().getName().equals("RandomProjects.PracticeQuestion2.Q6.CurrentAccount")){

                                CurrentAccount currentAccount = (CurrentAccount) account;
                                if (currentAccount.getAccountNumber() == accountNumber){

                                    System.out.println("Account is a Current Account");
                                    System.out.println("1. Edit Account Number");
                                    System.out.println("2. Deposit");
                                    System.out.println("3. Withdraw");
                                    System.out.print("Enter: ");

                                    int choice4 = sc.nextInt();
                                    sc.nextLine();

                                    if (choice4 == 1){

                                        System.out.println("Current Account number: " + currentAccount.getAccountNumber());
                                        System.out.print("Enter Account number: ");
                                        double accountNo = sc.nextDouble();
                                        sc.nextLine();

                                        currentAccount.setAccountNumber(accountNo);

                                        System.out.println("Account Edited");
                                    }

                                    else if (choice4 == 2){

                                        System.out.print("Deposit Amount: ");
                                        double depositAmount = sc.nextDouble();
                                        sc.nextLine();

                                        currentAccount.deposit(depositAmount);
                                        System.out.println("Account Edited");
                                    }

                                    else if (choice4 == 3){

                                        System.out.print("Withdraw Amount: ");
                                        double withdrawAmount = sc.nextDouble();
                                        sc.nextLine();

                                        currentAccount.withdraw(withdrawAmount);
                                        System.out.println("Account Edited");
                                    }

                                    else
                                        System.out.println("Invalid Choice");
                                }
                            }
                        }
                    }

                    break;

                case 3:
                    System.out.println("1. Based on Account number: ");
                    System.out.println("2. All");
                    System.out.print("Enter your choice: ");

                    choice2 = sc.nextInt();
                    sc.nextLine();

                    if (choice2 == 1) {

                        System.out.print("Enter Account number: ");
                        double accountNum = sc.nextDouble();
                        sc.nextLine();

                        for (Account account : bank.accounts) {

                            if(account != null) {

                                if (account.getClass().getName().equals("RandomProjects.PracticeQuestion2.Q6.SavingsAccount")) {
                                    SavingsAccount savingsAccount = (SavingsAccount) account;

                                    if (savingsAccount.getAccountNumber() == accountNum) {

                                        printSavingsAccounts(savingsAccount);
                                    }
                                }

                                else if (account.getClass().getName().equals("RandomProjects.PracticeQuestion2.Q6.CurrentAccount")) {

                                    CurrentAccount currentAccount = (CurrentAccount) account;

                                    if (currentAccount.getAccountNumber() == accountNum) {

                                        printCurrentsAccounts(currentAccount);
                                    }
                                }

                                else
                                    System.out.println("Error !");
                            }
                        }
                    }

                    else if (choice2 == 2) {

                        for (Account account : bank.accounts) {

                            if(account != null) {

                                if (account.getClass().getName().equals("RandomProjects.PracticeQuestion2.Q6.CurrentAccount")) {

                                    CurrentAccount currentAccount = (CurrentAccount) account;
                                    printCurrentsAccounts(currentAccount);
                                }

                                else if (account.getClass().getName().equals("RandomProjects.PracticeQuestion2.Q6.SavingsAccount")) {

                                    SavingsAccount savingsAccount = (SavingsAccount) account;
                                    printSavingsAccounts(savingsAccount);
                                }

                                else
                                    System.out.println("Error !");

                                System.out.println("------------------------------------------------------------------");
                            }
                        }
                    }

                    else
                        System.out.println("Invalid Choice");

                    break;

                case 4:
                    sc.close();
                    System.out.println("Exited !");
                    return;

                default:
                    System.out.println("Invalid Choice");
                    break;
            }
        }
    }

    public static void printSavingsAccounts(SavingsAccount savingsAccount) {

        System.out.println("Account Type: Savings Account");
        System.out.println("Account Number: " + savingsAccount.getAccountNumber());
        System.out.println("Account Balance: " + savingsAccount.getBalance());
        System.out.println("Interest for 12%: " + savingsAccount.calculateInterest(12));
    }

    public static void printCurrentsAccounts(CurrentAccount currentAccount) {

        System.out.println("Account Type: Current Account");
        System.out.println("Account Number: " + currentAccount.getAccountNumber());
        System.out.println("Account Balance: " + currentAccount.getBalance());
    }
}

class Bank{

    Account[] accounts = new Account[100];
    private int accountsIndex = -1;

    void addSavingsAccount(SavingsAccount savingsAccount){

        accounts[++accountsIndex] = savingsAccount;
    }

    void addCurrentAccount(CurrentAccount currentAccount){

        accounts[++accountsIndex] = currentAccount;
    }
}

class SavingsAccount implements Account{

    private double balance;
    private double accountNumber;

    public SavingsAccount(double accountNumber){

        this.balance = 0;
        this.accountNumber = accountNumber;
    }

    public double getAccountNumber(){
        return accountNumber;
    }

    public void setAccountNumber(double accountNumber){
        this.accountNumber = accountNumber;
    }

    @Override
    public void deposit(double amount) {

        balance += amount;
        System.out.println("Deposited " + amount + " to the balance of " + balance);
    }

    @Override
    public void withdraw(double amount) {

        if (balance >= amount) {
            balance -= amount;
            System.out.println("Withdrawn " + amount + " from the balance of " + balance);
        }

        else
            System.out.println("Insufficient balance");
    }

    @Override
    public double getBalance() {
        return balance;
    }

    @Override
    public double calculateInterest(double interest) {

        return  balance * interest / 100;
    }
}

class CurrentAccount implements Account{

    private double balance;
    private double overDraftAmount;
    private  double accountNumber;

    public CurrentAccount(double accountNumber, double overDraftAmount){
        this.balance = 0;
        this.accountNumber = accountNumber;
        this.overDraftAmount = overDraftAmount;
    }

    public double getAccountNumber(){
        return accountNumber;
    }

    public void setAccountNumber(double accountNumber){
        this.accountNumber = accountNumber;
    }

    public double getOverDraftAmount(){
        return overDraftAmount;
    }

    public void setOverDraftAmount(double overDraftAmount){
        this.overDraftAmount = overDraftAmount;
    }

    @Override
    public void deposit(double amount) {

        balance += amount;
        System.out.println("Deposited " + amount + " to the balance of " + balance);
    }

    @Override
    public double calculateInterest(double interest) {
        return 0;
    }

    @Override
    public void withdraw(double amount) {

        if(balance < -overDraftAmount){

            System.out.println("Insufficient balance");
        }

        balance -= amount;
        System.out.println("Withdrawn " + amount + " from the balance of " + balance);
    }

    @Override
    public double getBalance() {
        return balance;
    }
}

interface Account {

    void deposit(double amount);
    void withdraw(double amount);
    double getBalance();
    double calculateInterest(double interest);
}