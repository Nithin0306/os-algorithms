#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define N 5

sem_t chopstick[N];   // each chopstick is a semaphore

void *philosopher(void *num)
{
    int i = *(int *)num;

    while(1)
    {
        printf("Philosopher %d is thinking\n", i);
        sleep(1);

        // pick up left chopstick
        sem_wait(&chopstick[i]);

        // pick up right chopstick
        sem_wait(&chopstick[(i + 1) % N]);

        printf("Philosopher %d is eating\n", i);
        sleep(2);

        // put down left chopstick
        sem_post(&chopstick[i]);

        // put down right chopstick
        sem_post(&chopstick[(i + 1) % N]);
    }

    return NULL;
}

int main()
{
    pthread_t phil[N];
    int id[N];

    // initialize all chopsticks
    for(int i = 0; i < N; i++)
        sem_init(&chopstick[i], 0, 1);

    // create philosopher threads
    for(int i = 0; i < N; i++)
    {
        id[i] = i;
        pthread_create(&phil[i], NULL, philosopher, &id[i]);
    }

    for(int i = 0; i < N; i++)
        pthread_join(phil[i], NULL);

    return 0;
}