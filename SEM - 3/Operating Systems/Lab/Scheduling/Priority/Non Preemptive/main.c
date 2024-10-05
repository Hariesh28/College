/*
    A PROGRAM TO IMPLEMENT PRIORITY SCHEDULING ALGORITHM (NON PREEMPTIVE)

    Higher Priority Value Has Higher Priority In The Execution

    If the command-line argument "detailed" is passed while running the program,
    the execution will provide a step-by-step explanation with detailed information
    about each process during the CPU execution.

    Example Usage:
    ./program_name detailed
*/


#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define and &&
#define or ||

#define INITIAL_QUEUE_SIZE 1

#define DISPLAY_SIZE 2  // Adjust this value to modify the width of the Gantt chart display.
/*
    DISPLAY_SIZE affects the spacing of the Gantt chart.
    Increase DISPLAY_SIZE if the Gantt chart looks too narrow or decrease it if it's too wide.
    This value controls the horizontal space for each process in the Gantt chart visualization.
*/


int no_of_program = 0;
bool DETAILED = false;

// Define Datatypes

typedef struct program {

    int p_id;
    int arrival_time;
    int burst_time;
    int priority;
} program;

typedef struct process {

    int p_id;
    int arrival_time;
    int burst_time;
    int priority;
    int remaining_time;
    bool executed_once;
    int response_time;
    int waiting_time;
    int turnaround_time;
} process;

typedef struct queue {

    process **processes;
    int front;
    int rear;
    int size;
    int capacity;
} queue;

typedef struct gantt_chart_node {

    int p_id;
    int start_clock;
    int end_clock;
    struct gantt_chart_node *next_node;
} gantt_chart_node;

// Declare Queue Methods

// Initialize the queue with default capacity
void init_queue (queue *queue){

    queue->front = -1;
    queue->rear = -1;
    queue->size = 0;
    queue->capacity = INITIAL_QUEUE_SIZE;

    queue->processes = (process **) malloc (queue->capacity * sizeof(process *));

    if(!queue->processes){

        printf("Memory Allocation Failed !\n");
        exit(1);
    }
}


// Check if the queue is full
bool isFull (queue *queue){

    return queue->size == queue->capacity;
}

// Check if the queue is empty
bool isEmpty (queue *queue){

    return queue->size == 0;
}

// Double the size of the queue
void increase_size (queue *queue){

    int new_capacity = queue->capacity * 2;

    queue->processes = (process **) realloc(queue->processes, new_capacity * sizeof(process *));

    if (!queue->processes){

        printf("Memory Re-Allocation Failed !\n");
        exit(1);
    }

    // If the queue is wrapped around
    if (queue->front > queue->rear){

        // Move all the processes from the start of the array to the end of the queue
        for (int i = 0; i <= queue->rear; i++)
            queue->processes[queue->capacity + i] = queue->processes[i];

        queue->rear = queue->capacity + queue->rear;
    }

    queue->capacity = new_capacity;
}

// Get the size of the queue
int getSize (queue *queue){

    return queue->size;
}

// Enqueue a process
void enqueue (queue *queue, process *process){

    if (isFull(queue)) increase_size(queue);

    if (isEmpty(queue)){

        queue->front = 0;
        queue->rear = 0;

        queue->processes[0] = process;

    } else {

        queue->rear = (queue->rear + 1) % queue->capacity;
        queue->processes[queue->rear] = process;
    }

    queue->size++;
}

// Dequeue a process
process* dequeue (queue *queue){

    if (isEmpty(queue)) return NULL;

    process *return_process = queue->processes[queue->front];

    queue->front = (queue->front + 1) % queue->capacity;
    queue->size--;

    return return_process;
}

// Dequeue based on priority
process* dequeue_priority(queue *queue){

    if (isEmpty(queue)) return NULL;

    process *return_process = queue->processes[queue->front];

    int current_process_index = queue->front;
    int priority_index = queue->front;

    // Check every process from the start until the rear (exclusive)
    while (current_process_index != queue->rear){

        if (queue->processes[current_process_index]->priority > return_process->priority){

            return_process = queue->processes[current_process_index];
            priority_index = current_process_index;
        }

        current_process_index = (current_process_index + 1) % queue->capacity;
    }

    // Check the last process
    if (queue->processes[queue->rear]->priority > return_process->priority){

        return_process = queue->processes[queue->rear];
        priority_index = current_process_index;
    }

    // If it is the start process, just increment front
    if (priority_index == queue->front) queue->front = (queue->front + 1) % queue->capacity;

    // Shift all the process after the dequeued process one step before
    else {

        int current_index = priority_index;
        int next_index;

        while (current_index != queue->rear){

            next_index = (current_index + 1) % queue->capacity;

            queue->processes[current_index] = queue->processes[next_index];

            current_index = next_index;
        }

        queue->rear = (queue->rear - 1 + queue->capacity) % queue->capacity;
    }

    queue->size--;

    return return_process;
}

// Displays

// Display all the details of a process
void display_process (process *process){

    printf("p_id: %d, ",process->p_id);
    printf("Arrival Time: %d, ",process->arrival_time);
    printf("Burst Time: %d, ",process->burst_time);
    printf("Priority: %d, ", process->priority);
    printf("Remaining Time: %d, ",process->remaining_time);
    printf("Executed Once: %d, ",process->executed_once);
    printf("Response Time: %d, ",process->response_time);
    printf("Waiting Time: %d, ",process->waiting_time);
    printf("Turn Around Time: %d\n",process->turnaround_time);
}

// Display only important details
void display_process_report (process *process){

    printf("p_id: %d, ", process->p_id);
    printf("Response Time: %d, ", process->response_time);
    printf("Waiting Time: %d, ", process->waiting_time);
    printf("Turnaround Time: %d\n", process->turnaround_time);
}


// Other Methods

// Create a process from a program
process* create_process (program *program){

    process *new_process = (process *) malloc(sizeof(process));

    if (!new_process){

        printf("Process Creation Failed !\n");
        exit(1);
    }

    new_process->p_id = program->p_id;
    new_process->arrival_time = program->arrival_time;
    new_process->burst_time = program->burst_time;
    new_process->priority = program->priority;

    new_process->remaining_time = program->burst_time;
    new_process->executed_once = false;
    new_process->response_time = 0;
    new_process->waiting_time = 0;
    new_process->turnaround_time = 0;

    return new_process;
}

// Get the process ID, arrival time, and burst time for each program from the user, with input validation
program get_program (int process_number){

    int p_id, arrival_time, burst_time, priority;

    while (true){

        printf("Process id of program %d: ", process_number);
        scanf("%d", &p_id);

        if (p_id <= 0) printf("Invalid Process ID\n");
        else break;
    }

    while (true){

        printf("Arrival time of program %d: ", process_number);
        scanf("%d", &arrival_time);

        if (arrival_time < 0) printf("Arrival Time Can't Be Negative !\n");
        else break;
    }

    while (true){

        printf("Burst time of program %d: ", process_number);
        scanf("%d", &burst_time);

        if (burst_time <= 0) printf("Burst Time Can't Be Negative or Zero !\n");
        else break;
    }

    while (true){

        printf("Priority of program %d: ", process_number);
        scanf("%d", &priority);

        if (priority < 0) printf("Priority Can't Be Negative");
        else break;
    }

    program program = {p_id, arrival_time, burst_time, priority};

    return program;
}

// Get all the programs from the user
program* get_all_programs (){

    printf("Enter the number of program: ");
    scanf("%d", &no_of_program);

    program *programs = (program *) malloc(no_of_program * sizeof(program));

    if (!programs){

        printf("Program Creation Failed !\n");
        exit(1);
    }

    for (int i = 0; i < no_of_program; i++){

        printf("Enter the details of %d\n", i+1);
        program program = get_program(i+1);
        programs[i] = program;
    }

    return programs;
}

// Returns the length of a number
int findLength (int number){

    if (number == 0) return 1;
    if (number < 0) number = -number;

    return (int) log10(number) + 1;
}

// Logs the process execution information to the Gantt chart, updating it with start and end clock cycles
void log_gantt (int p_id, int clock, gantt_chart_node **head, gantt_chart_node **tail){

    // If head is null or next node is different from previous node
    if (!(*head) or ((*tail)->p_id != p_id)){

        gantt_chart_node *new_node = (gantt_chart_node *) malloc(sizeof(gantt_chart_node));
        new_node->p_id = p_id;
        new_node->start_clock = clock;
        new_node->end_clock = clock;
        new_node->next_node = NULL;

        if (!(*head)) *head = new_node;
        else (*tail)->next_node = new_node;

        *tail = new_node;
    }

    // Else update the tail node's clock
    else (*tail)->end_clock = clock;
}

// Display the Gantt Chart Log_gantt
void display_log_gantt (gantt_chart_node *head, gantt_chart_node *tail){

    gantt_chart_node *current = head;

    while(current != tail){

        printf("%d:%d,%d -> ", current->p_id, current->start_clock, current->end_clock);
        current = current->next_node;
    }

    printf("%d:%d,%d\n", tail->p_id, tail->start_clock, tail->end_clock);
}

// Displays the Gantt chart in a graphical form, showing which process executed in which time slot
void display_gantt_chart(gantt_chart_node *head) {

    gantt_chart_node *current = head;
    int main_space = DISPLAY_SIZE * 7;
    int current_space;

    // Top line
    printf(" ");

    while (current) {

        for (int i = 0; i < main_space; i++) printf("-");
        printf(" ");
        current = current->next_node;
    }
    printf("\n");

    // p_id
    current = head;
    printf("|");
    while (current) {

        for (int i = 0; i < ((main_space - 2) / 2); i++) printf(" ");

        printf("P%d", current->p_id);

        int border = ((main_space - 2) / 2) + 1;
        if (main_space % 2 == 0) border--;
        for (int i = 0; i < border; i++) printf(" ");
        printf("|");

        current = current->next_node;
    }
    printf("\n");

    // Bottom Line
    current = head;
    printf(" ");

    while (current) {

        for (int i = 0; i < main_space; i++) printf("-");
        printf(" ");
        current = current->next_node;
    }
    printf("\n");

    // Clock Timings
    current = head;
    printf("%d", current->start_clock);
    while (current != NULL) {

        current_space = main_space - ((findLength(current->end_clock))/2);

        for (int i = 0; i < current_space; i++) printf(" ");

        printf("%d", current->end_clock + 1);
        current = current->next_node;
    }
    printf("\n");
}

// Free the memory of the gantt chart
void free_gantt(gantt_chart_node **head){

    while ((*head)){

        gantt_chart_node *temp = *head;
        (*head) = (*head)->next_node;
        free(temp);
    }
}


// Driver Code

int main (int argc, char *argv[]){

    if (argc > 1 and strcmp(argv[1], "detailed") == 0) DETAILED = true;

    program *programs = get_all_programs();

    // Create the ready queue
    queue ready_queue;
    init_queue(&ready_queue);

    process *terminated_processes[no_of_program];
    int terminated_processes_current = -1;

    process *current_process = NULL;
    int clock = -1;

    gantt_chart_node *head = NULL;
    gantt_chart_node *tail = NULL;

    printf("\nStarting CPU Execution\n");

    // CPU Execution Loop:
    // Simulates the CPU executing processes based on the FCFS scheduling algorithm.
    // The ready queue is populated with processes as they arrive, and each process is executed in order of arrival.

    while (true){

        clock++;

        // Add program to ready queue
        for (int i = 0; i < no_of_program; i++){

            if (programs[i].arrival_time == clock){

                process *process = create_process(&programs[i]);
                enqueue(&ready_queue, process);
            }
        }

        // Update Current Process
        if (!current_process)
            current_process = dequeue_priority(&ready_queue);

        // Stop CPU if all the programs are executed
        if (isEmpty(&ready_queue) and !current_process){

            printf("\nAll Processes Executed !\n");
            printf("Total Clock Cycles: %d\n", clock);
            break;
        }

        // Execute the Current Process
        if (current_process){

            current_process->remaining_time--;
            current_process->turnaround_time++;

            if (!current_process->executed_once)
                current_process->executed_once = true;

            log_gantt(current_process->p_id, clock, &head, &tail);

            if (DETAILED){

                // Display Info
                printf("\nAt Clock: %d\n", clock);
                display_process(current_process);
            }

            if (current_process->remaining_time == 0){

                terminated_processes[++terminated_processes_current] = current_process;
                current_process = NULL;
            }
        }

        // Update the values in the ready queue
        if (DETAILED)
            printf("Number of processes in the ready queue: %d\n", ready_queue.size);

        for (int i = 0; i < ready_queue.size; i++){

            int index = (ready_queue.front + i) % ready_queue.capacity;

            if (!ready_queue.processes[index]->executed_once)
                ready_queue.processes[index]->response_time++;

            ready_queue.processes[index]->waiting_time++;
            ready_queue.processes[index]->turnaround_time++;

            if (DETAILED)
                display_process(ready_queue.processes[index]);
        }
    }

    // Final Report:
    // Displays the response time, waiting time, and turnaround time for each process,
    // along with average turnaround time, throughput, and average waiting time.

    printf("\nFinal Report !\n");

    int total_waiting_time = 0;
    int total_turnaround_time = 0;

    for (int i = 0; i <= terminated_processes_current; i++){

        display_process_report(terminated_processes[i]);

        total_waiting_time += terminated_processes[i]->waiting_time;
        total_turnaround_time += terminated_processes[i]->turnaround_time;

        free(terminated_processes[i]);
    }

    free(programs);

    if (terminated_processes_current >= 0){

        printf("\nAverage Turnaround Time: %.2f\n", (float)total_turnaround_time / (terminated_processes_current + 1));
        printf("Throughput: %.2f programs per unit time\n", (float)(terminated_processes_current + 1) / (float)clock);
        printf("Average Waiting Time: %.2f\n", (float)total_waiting_time / (terminated_processes_current + 1));

    }

    printf("\nGantt Chart: \n");
    display_gantt_chart(head);

    free_gantt(&head);

    return 0;
}
