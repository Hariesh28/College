#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 100

// Define Datatypes

// basic program
typedef struct program{

    int p_id;
    int arrival_time;
    int burst_time;
} program;

// executable program
typedef struct executable_program{

    int p_id;
    int arrival_time;
    int burst_time;
    int remaining_time;
    bool executed_once;
    int response_time;
    int waiting_time;
    int turnaround_time;
} executable_program;

// queue used as ready queue
typedef struct queue{

    executable_program *executable_programs[MAX_QUEUE_SIZE];
    int front;
    int rear;
    int size;
} queue;


// Declare Queue Methods

// initialize the queue
void init_queue(queue *queue){

    queue->front = -1;
    queue->rear = -1;
    queue->size = 0;
}

// Checks if queue is full
bool isFull(queue *queue){

    return queue->size == MAX_QUEUE_SIZE;
}

// Checks if queue is Empty
bool isEmpty(queue *queue){

    return queue->size == 0;
}

// Gets the size of the queue
int getSize(queue *queue){

    return queue->size;
}

// Add a program to the queue
void enqueue(queue *queue, executable_program *executable_program){

    if(isFull(queue)){

        printf("Error !!! Queue is Full\n");
        return;
    }

    if(isEmpty(queue)){

        queue->front = 0;
        queue->rear = 0;
        queue->executable_programs[0] = executable_program;
    } else {

        queue->rear = (queue->rear + 1) % MAX_QUEUE_SIZE;
        queue->executable_programs[queue->rear] = executable_program;
    }

    queue->size++;
}

// Remove a program from the queue
executable_program* dequeue(queue *queue){

    if(isEmpty(queue)){
        return NULL;
    }

    executable_program *return_program = queue->executable_programs[queue->front];

    queue->front = (queue->front + 1) % MAX_QUEUE_SIZE;
    queue->size--;

    return return_program;
}

// Dequeue based on shortest job first
executable_program *dequeue_sjf(queue *queue){

    if(isEmpty(queue))
        return NULL;

    // Assign first programs as shortest
    executable_program *shortest = queue->executable_programs[queue->front];
    int current = queue->front;
    int shortest_index = queue->front;

    // Loop through all the programs in the queue to find the shortest program
    for(int i = 0; i < queue->size; i++){

        current = (queue->front + i) % MAX_QUEUE_SIZE;

        // Update shortest program if new shortest program is found
        if(queue->executable_programs[current]->remaining_time < shortest->remaining_time){

            shortest = queue->executable_programs[current];
            shortest_index = current;
        }
    }

    // If shortest is the first, just inc front
    if(queue->front == shortest_index)
        queue->front = ++queue->front % MAX_QUEUE_SIZE;

    else {

        // Shift all the programs one position before it's current position
        // Simply overwrite the shortest program
        while(shortest_index != queue->rear){

            queue->executable_programs[shortest_index] = queue->executable_programs[(shortest_index + 1) % MAX_QUEUE_SIZE];
            shortest_index = ++shortest_index % MAX_QUEUE_SIZE;
        }

        // dec rear
        queue->rear = (queue->rear - 1 + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
    }

    queue->size--;
    return shortest;
}

// display all the details of the program
void display_executable_program(executable_program *executable_program){

    printf("p_id: %d, ", executable_program->p_id);
    printf("Arrival Time: %d, ", executable_program->arrival_time);
    printf("Burst Time: %d, ", executable_program->burst_time);
    printf("Remaining Time: %d, ", executable_program->remaining_time);
    printf("Executed Once: %d, ", executable_program->executed_once);
    printf("Response Time: %d, ", executable_program->response_time);
    printf("Waiting Time: %d, ", executable_program->waiting_time);
    printf("Turn Around Time: %d\n", executable_program->turnaround_time);
}

// display selected details of the program
void display_executable_program_report(executable_program *executable_program){

    printf("p_id: %d -> ", executable_program->p_id);
    printf("Response Time: %d, ", executable_program->response_time);
    printf("Waiting Time: %d, ", executable_program->waiting_time);
    printf("Turnaround Time: %d\n", executable_program->turnaround_time);
}

// Creates a executable program from a program
executable_program* create_executable_program(program program){

    executable_program *new_executable_program = (executable_program *) malloc(sizeof(executable_program));

    if(!new_executable_program){
        printf("Memory Allocation Failed !");
        exit(1);
    }

    new_executable_program->p_id = program.p_id;
    new_executable_program->arrival_time = program.arrival_time;
    new_executable_program->burst_time = program.burst_time;
    new_executable_program->remaining_time = program.burst_time;
    new_executable_program->executed_once = false;
    new_executable_program->response_time = 0;
    new_executable_program->waiting_time = 0;
    new_executable_program->turnaround_time = 0;

    return new_executable_program;
}

//Get program from user
program get_program(int process_number){

    int p_id, arrival_time, burst_time;

    printf("Process id of program %d: ", process_number);
    scanf("%d", &p_id);

    printf("Arrival time of program %d: ", process_number);
    scanf("%d", &arrival_time);

    printf("Burst time of program %d: ", process_number);
    scanf("%d", &burst_time);

    program program = {p_id, arrival_time, burst_time};

    return program;
}



// Driver Code
int main(){


    // Get Programs from user
    int no_of_programs;
    printf("Enter the number of programs: ");
    scanf("%d", &no_of_programs);

    program *programs = (program *) malloc(no_of_programs * sizeof(program));

    if (programs == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    for(int i = 0; i < no_of_programs; i++){

        printf("Enter details of program %d\n", i+1);
        program program = get_program(i+1);
        programs[i] = program;
    }

    // initialize ready queue
    queue ready_queue;
    init_queue(&ready_queue);

    executable_program *completed_programs[no_of_programs];
    int completed_programs_current = 0;

    executable_program *current_program = NULL;
    int clock = -1;

    // CPU
    while(true){

        clock++;

        // Add programs to ready queue
        for(int i = 0; i < no_of_programs; i++){

            if(programs[i].arrival_time == clock){

                // Create program to process
                executable_program *new_exe = create_executable_program(programs[i]);
                enqueue(&ready_queue, new_exe);
            }
        }

        // Update current program
        if(!current_program)
            current_program = dequeue_sjf(&ready_queue);

        // Stop CPU if all programs are executed
        if(isEmpty(&ready_queue) && !current_program){
            printf("\nProgram Completed !\nTotal clock cycles: %d\n", clock);
            break;
        }

        // Execute the program
        if(current_program){

            current_program->remaining_time--;
            current_program->turnaround_time++;

            if (!current_program->executed_once)
                current_program->executed_once = true;

            // Display info
            printf("\nAt Clock: %d\n", clock);
            if(current_program)
                display_executable_program(current_program);

            // Stop execution if burst time is done
            if(current_program->remaining_time == 0){

                completed_programs[completed_programs_current++] = current_program;
                current_program = NULL;
            }
        }

        // Update the params in ready queue
        printf("Number of programs in ready queue: %d\n", ready_queue.size);
        for(int i = 0; i < ready_queue.size; i++){

            int index = (ready_queue.front + i) % MAX_QUEUE_SIZE;

            if(!ready_queue.executable_programs[index]->executed_once)
                ready_queue.executable_programs[index]->response_time++;

            ready_queue.executable_programs[index]->waiting_time++;
            ready_queue.executable_programs[index]->turnaround_time++;

            // Display the program
            display_executable_program(ready_queue.executable_programs[index]);
        }
    }


    // Display the final result
    printf("\nFinal Report !\n");

    int total_waiting_time = 0;
    int total_turnaround_time = 0;

    for (int i = 0; i < completed_programs_current; i++){

        display_executable_program_report(completed_programs[i]);
        total_waiting_time += completed_programs[i]->waiting_time;
        total_turnaround_time += completed_programs[i]->turnaround_time;
        free(completed_programs[i]);
    }

    free(programs);
    printf("Average Waiting Time: %f\n", (float)total_waiting_time / completed_programs_current);
    printf("Average Turnaround Time: %f\n", (float)total_turnaround_time / completed_programs_current);
    printf("Throughput: %f programs per unit time\n", (float)completed_programs_current / (float)clock);

    return 0;
}