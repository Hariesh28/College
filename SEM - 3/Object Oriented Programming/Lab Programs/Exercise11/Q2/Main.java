package Exercise11.Q2;

class myThread implements Runnable {

    private final String message;

    public myThread(String message){

        this.message = message;
    }

    @Override
    public void run(){
        
        while (true){

            System.out.println(message);

            try {

                Thread.sleep(300);
            } catch (InterruptedException exception){
                
                Thread.currentThread().interrupt();
                break;
            }
        }
    }
}

public class Main {
    
    public static void main(String[] args) {
        
        Thread thread1 = new Thread(new myThread("HI"));
        Thread thread2 = new Thread(new myThread("AI"));

        thread1.start();
        thread2.start();

//      Wait Main Thread For 3 seconds
        try {

            Thread.sleep(3000);
        } catch (InterruptedException exception){

            System.out.println(exception.getMessage());
        }

//      Kill the threads
        thread1.interrupt();
        thread2.interrupt();
    }
}
