#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

#define BUFFER_SIZE 5

int buffer[BUFFER_SIZE];
int in = 0, out = 0;

sem_t empty, full;
pthread_mutex_t mutex;

void *producer(void *arg) {
    int item = 1;

    sem_wait(&empty);            // wait for empty slot
    pthread_mutex_lock(&mutex);  // lock buffer

    buffer[in] = item;
    in = (in + 1) % BUFFER_SIZE;
    printf("Produced\n");

    pthread_mutex_unlock(&mutex);
    sem_post(&full);             // signal item available
    return NULL;
}

void *consumer(void *arg) {

    sem_wait(&full);             // wait for item
    pthread_mutex_lock(&mutex);

    int item = buffer[out];
    out = (out + 1) % BUFFER_SIZE;
    printf("Consumed\n");

    pthread_mutex_unlock(&mutex);
    sem_post(&empty);            // signal space available
    return NULL;
}