#include <stdio.h>
#include <stdlib.h>
#include <semaphore.h>
#include <pthread.h>
#include <unistd.h>

#define N 5

sem_t chopstick[N];
sem_t mutex;

void *philosopher(void *value){

    while (1){

        int id = *(int *) value;

        printf("Philosopher %d is Thinking\n", id+1);
        sleep(1);

        sem_wait(&mutex);

        sem_wait(&chopstick[id]);
        sem_wait(&chopstick[(id+1)]);

        printf("Philosopher %d is eating\n", id+1);
        sleep(2);

        sem_post(&chopstick[id]);
        sem_post(&chopstick[(id+1)]);

        sem_post(&mutex);

        printf("Philosopher %d has finished eating\n", id+1);
    }
}

int main(){

    pthread_t threads[N];
    int thread_ids[N];

    sem_init(&mutex, 0, N-1);
    for (int i = 0; i < N; i++) sem_init(&chopstick[i], 0, 1);

    for (int i = 0; i < N; i++){

        thread_ids[i] = i;
        pthread_create(&threads[i], NULL, philosopher, (void *) &thread_ids[i]);
    }

    for (int i = 0; i < N; i++) pthread_join(threads[i], NULL);

    sem_destroy(&mutex);
    for (int i = 0; i < N; i++) sem_destroy(&chopstick[i]);

    return 0;
}