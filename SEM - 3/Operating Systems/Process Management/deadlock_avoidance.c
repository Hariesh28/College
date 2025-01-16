#include <stdio.h>
#include <stdbool.h>

#define PROCESS 5
#define RESOURCE 3

int max[PROCESS][RESOURCE];
int need[PROCESS][RESOURCE];
int allocation[PROCESS][RESOURCE];
int available[RESOURCE];

void calculate_need(){

    for (int i = 0; i < PROCESS; i++)
        for (int j = 0; j < RESOURCE; j++)
            need[i][j] = max[i][j] - allocation[i][j];
}

bool isSafe(){

    int work[RESOURCE];
    bool finished[PROCESS] = {false};

    int safeSequence[PROCESS];
    int safeIndex = -1;

    int count = 0;
    bool found;

    for (int i = 0; i < RESOURCE; i++) work[i] = available[i];

    while (count < PROCESS){

        found = false;

        for (int p = 0; p < PROCESS; p++){

            if (!finished[p]){

                int j;

                for (j = 0; j < RESOURCE; j++){

                    if (need[p][j] > work[j]) break; // Not completed
                }

                // Completed
                if (j == RESOURCE){

                    for (int k = 0; k < RESOURCE; k++) work[k] += allocation[p][k];

                    finished[p] = true;
                    safeSequence[++safeIndex] = p;
                    found = true;
                    count++;
                }
            }
        }

        if (!found){

            printf("Deadlock Detected !\n");
            return false;
        }
    }

    printf("No Deadlock Detected !\n");
    printf("Safe Sequence: ");
    for (int i = 0; i <= safeIndex; i++) printf("P%d ", safeSequence[i]);

    return true;
}

int requestResource(int process_id, int request[]){

    for (int i = 0; i < RESOURCE; i++){

        if (request[i] > need[process_id][i]){

            printf("Need is less\n");
            return -1;
        }
    }

    for (int i = 0; i < RESOURCE; i++){

        if (request[i] > available[i]){

            printf("Not available\n");
            return -1;
        }
    }

    printf("hey");

    // Allocate
    for (int i = 0; i < RESOURCE; i++){

        allocation[process_id][i] += request[i];
        need[process_id][i] -= request[i];
        available[i] -= request[i];
    }
    printf("Hi");
    if (isSafe()){

        printf("Safe :)\n");
        return 0;
    }

    else {

        // RollBack
        for (int i = 0; i < RESOURCE; i++){

            allocation[process_id][i] -= request[i];
            need[process_id][i] += request[i];
            available[i] += request[i];
        }

        printf("Not Safe :(\n");
        return -1;
    }
}

int main(){

    printf("Enter Max Matrix: ");
    for (int i = 0; i < PROCESS; i++)
        for (int j = 0; j < RESOURCE; j++)
            scanf("%d", &max[i][j]);

    printf("Enter allocation: ");
    for (int i = 0; i < PROCESS; i++)
        for (int j = 0; j < RESOURCE; j++)
            scanf("%d", &allocation[i][j]);

    printf("Available: ");
    for (int i = 0; i < RESOURCE; i++)
        scanf("%d", &available[i]);


    calculate_need();

    isSafe();

    // int process_id;
    // int request[RESOURCE];

    // printf("Enter process id: ");
    // scanf("%d", &process_id);

    // printf("Enter Request Resources: ");
    // for (int i = 0; i < RESOURCE; i++)
    //     scanf("%d", &request[i]);

    // requestResource(process_id, request);

    return 0;
}