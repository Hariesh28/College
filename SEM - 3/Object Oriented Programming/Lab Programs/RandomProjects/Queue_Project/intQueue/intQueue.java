package RandomProjects.Queue_Project.intQueue;

public class intQueue {

    private long[] queue;
    private int front;
    private int rear;
    private int size;

    public intQueue(long[] array){

        this.queue = array;
        this.front = 0;
        this.rear = array.length-1;
        this.size = array.length;
    }

    public intQueue(long value){

        this.queue = new long[1];
        this.queue[0] = value;
        this.front = 0;
        this.rear = 0;
        this.size = 1;
    }

    public intQueue(int value){

        this((long) value);
    }

    public intQueue(){

        this.queue = new long[10];
        this.front = -1;
        this.rear = -1;
        this.size = 0;
    }

    public boolean isEmpty(){
        return size==0;
    }

    private boolean isFull(){
        return size==queue.length;
    }

    public int size(){
        return size;
    }

    public int memorySize(){
        return queue.length;
    }

    private void resizeQueue(String type){

        int newSize = type.equals("grow") ? queue.length*2 : queue.length/2;

        long[] newQueue = new long[newSize];

        int temp = front;
        int index = 0;

        while(true){

            newQueue[index] = queue[temp];
            if(temp == rear) break;
            temp = ++temp % queue.length;
            index++;
        }

        this.queue = newQueue;
        this.front = 0;
        this.rear = size-1;
    }

    public void enqueue(int value){

        if(isFull()) resizeQueue("grow");

        if(isEmpty()){
            front = 0;
            rear = 0;
        } else
            rear = ++rear % queue.length;

        queue[rear] = value;
        size++;
    }

    public long dequeue(){

        if(isEmpty()) return -1L;

        long result = queue[front];

        if(front == rear){
            front = -1;
            rear = -1;
            size = 0;
        }

        else {

            front = ++front % queue.length;
            size--;
        }

        if(size <= queue.length/2 && size != 0) resizeQueue("shrink");

        return result;
    }

    public long peek(){

        if(isEmpty()) return -1L;

        return queue[front];
    }

    public void print(){

        if(isEmpty()) return;

        int temp = front;

        while(true){

            System.out.print(queue[temp] + " ");
            if(temp == rear) break;
            temp = ++temp % queue.length;
        }

        System.out.println();
    }
}
