package Exercise11.Q1;

class myThread extends Thread {

    @Override
    public void run (){

        System.out.println("Today is hot");
        System.out.println("Today is humid");
        System.out.println("Today is sunny");
    }
}

public class Main {
    
    public static void main(String[] args) {
        
        myThread thread1 = new myThread();
        myThread thread2 = new myThread();

        thread1.start();
        thread2.start();

//      Wait for the threads to complete
        try {

            thread1.join();
            thread2.join();
        } catch (Exception exception){

            System.out.println(exception.getMessage());
        }
    }
}
