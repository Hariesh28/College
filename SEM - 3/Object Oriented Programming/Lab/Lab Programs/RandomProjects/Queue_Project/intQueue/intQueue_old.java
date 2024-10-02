package RandomProjects.Queue_Project.intQueue;

public class intQueue_old {

    private long[] queue;
    private int front;
    private int rear;
    private int size;

    public intQueue_old(long[] array){

        this.queue = array;
        this.front = 0;
        this.rear = array.length-1;
        this.size = array.length;
    }

    public intQueue_old(int value){

        this.queue = new long[1];
        this.queue[0] = value;
        this.front = 0;
        this.rear = 0;
        this.size = 1;
    }

    public intQueue_old(long value){

        this.queue = new long[1];
        this.queue[0] = value;
        this.front = 0;
        this.rear = 0;
        this.size = 1;
    }

    public intQueue_old(){

        this.queue = new long[1];
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

    private long[] expandArray(long[] array, String type){

        if(type.equals("grow")){

            long[] newArray = new long[array.length*2];

            int temp = front;
            int index = 0;

            while (true){

                newArray[index] = array[temp];
                if(temp == rear) break;
                temp = ++temp % array.length;
                index++;
            }

            return newArray;
        }

        else if(type.equals("shrink")){

            long[] newArray = new long[array.length/2];
            int temp = front;
            int index = 0;

            while (true){

                newArray[index] = array[temp];
                if(temp == rear) break;
                temp = ++temp % array.length;
                index++;
            }

            return newArray;
        }

        else
            return array;
    }

    public boolean enqueue(int value){

        if(isFull()) {

            queue = expandArray(queue, "grow");
            front = 0;
            rear = size - 1;
        }

        if(isEmpty()){

            front = 0;
            rear = 0;
        } else
            rear = ++rear % queue.length;

        queue[rear] = value;
        size++;
        return true;
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

        if(size == queue.length/2 && size != 0) {

            queue = expandArray(queue, "shrink");
            front = 0;
            rear = size - 1;
        }

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
