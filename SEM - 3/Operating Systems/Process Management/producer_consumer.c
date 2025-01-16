#include <stdio.h>
#include <stdlib.h>
#include <semaphore.h>
#include <unistd.h>
#include <pthread.h>

sem_t empty;
sem_t full;
pthread_mutex_t mutex;

int buffer[5];
int count = 0;

void *producer(void *param){

    while (1){

        int item = rand() % 100;
        sleep(1);

        sem_wait(&empty);

        pthread_mutex_lock(&mutex);

        buffer[count] = item;
        count++;
        printf("Produced: %d\n", item);
        sleep(2);

        pthread_mutex_unlock(&mutex);

        sem_post(&full);
    }
}

void *consumer(void *param){

    while (1){

        sem_wait(&full);

        pthread_mutex_lock(&mutex);

        count--;
        int item = buffer[count];
        printf("Consumed: %d\n", item);
        sleep(2);

        pthread_mutex_unlock(&mutex);

        sem_post(&empty);
    }
}

int main(){

    pthread_t prod, con;

    sem_init(&empty, 0, 5);
    sem_init(&full, 0, 0);
    pthread_mutex_init(&mutex, NULL);


    pthread_create(&prod, NULL, producer, NULL);
    pthread_create(&con, NULL, consumer, NULL);

    pthread_join(prod, NULL);
    pthread_join(con, NULL);

    sem_destroy(&empty);
    sem_destroy(&full);

    pthread_mutex_destroy(&mutex);

    return 0;
}