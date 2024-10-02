package RandomProjects.Queue_Project.mainProgram;

import RandomProjects.Queue_Project.intQueue.intQueue;

public class main_program {

    public static void main(String[] args) {

        intQueue queue = new intQueue(new long[]{0, 1, 2, 3, 4, 5, 6, 7, 8, 9});

        System.out.println(queue.size());
        queue.print();

        System.out.println(queue.dequeue());
        queue.print();

        System.out.println(queue.size());
        System.out.println(queue.dequeue());
        queue.print();

        System.out.println(queue.size());
        System.out.println(queue.dequeue());
        queue.print();

        System.out.println(queue.size());
        System.out.println(queue.dequeue());
        queue.print();

        System.out.println(queue.size());
        System.out.println(queue.dequeue());
        queue.print();

        System.out.println(queue.size());
        System.out.println(queue.dequeue());
        queue.print();

        System.out.println(queue.size());
        System.out.println(queue.dequeue());
        queue.print();

        System.out.println(queue.size());
        System.out.println(queue.dequeue());
        queue.print();

        System.out.println(queue.size());
        System.out.println(queue.dequeue());
        queue.print();

        System.out.println(queue.size());
        System.out.println(queue.dequeue());
        queue.print();

        System.out.println("hi");
        System.out.println(queue.size());
        System.out.println(queue.dequeue());
        queue.print();

        System.out.println(queue.size());
        System.out.println(queue.dequeue());
        queue.print();
    }
}

