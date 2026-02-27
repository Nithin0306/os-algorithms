#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

#define N 5
sem_t chopstick[N];

void *philosopher(void *num) {
    int i = *(int *)num;

    sem_wait(&chopstick[i]);              // pick left
    sem_wait(&chopstick[(i+1)%N]);        // pick right

    printf("Philosopher %d eating\n", i);

    sem_post(&chopstick[i]);              // put left
    sem_post(&chopstick[(i+1)%N]);        // put right
    return NULL;
}