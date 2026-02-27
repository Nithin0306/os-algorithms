#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

int read_count = 0;
sem_t rw_mutex, mutex;

void *reader(void *arg) {

    sem_wait(&mutex);
    read_count++;

    if (read_count == 1)
        sem_wait(&rw_mutex);   // first reader blocks writers

    sem_post(&mutex);

    printf("Reading...\n");

    sem_wait(&mutex);
    read_count--;

    if (read_count == 0)
        sem_post(&rw_mutex);   // last reader allows writers

    sem_post(&mutex);
    return NULL;
}

void *writer(void *arg) {

    sem_wait(&rw_mutex);   // only one writer allowed

    printf("Writing...\n");

    sem_post(&rw_mutex);
    return NULL;
}