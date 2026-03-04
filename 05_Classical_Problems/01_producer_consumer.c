#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define BUFFER_SIZE 5

int buffer[BUFFER_SIZE];
int in = 0;
int out = 0;

sem_t empty;   // counts empty slots in buffer
sem_t full;    // counts filled slots in buffer
sem_t mutex;   // ensures mutual exclusion when accessing buffer

void *producer(void *arg)
{
    int item = 1;

    for(int i = 0; i < 5; i++)
    {
        sem_wait(&empty);   // wait if buffer is full
        sem_wait(&mutex);   // enter critical section

        buffer[in] = item;
        printf("Produced %d at index %d\n", item, in);

        in = (in + 1) % BUFFER_SIZE;

        sem_post(&mutex);   // leave critical section
        sem_post(&full);    // signal that buffer has new item

        sleep(1);           // simulate production time
        item++;
    }

    return NULL;
}

void *consumer(void *arg)
{
    int item;

    for(int i = 0; i < 5; i++)
    {
        sem_wait(&full);    // wait if buffer empty
        sem_wait(&mutex);   // enter critical section

        item = buffer[out];
        printf("Consumed %d from index %d\n", item, out);

        out = (out + 1) % BUFFER_SIZE;

        sem_post(&mutex);   // leave critical section
        sem_post(&empty);   // signal that buffer has free slot

        sleep(1);           // simulate consumption time
    }

    return NULL;
}

int main()
{
    pthread_t p, c;

    // initialize semaphores
    sem_init(&empty, 0, BUFFER_SIZE);
    sem_init(&full, 0, 0);
    sem_init(&mutex, 0, 1);

    pthread_create(&p, NULL, producer, NULL);
    pthread_create(&c, NULL, consumer, NULL);

    pthread_join(p, NULL);
    pthread_join(c, NULL);

    sem_destroy(&empty);
    sem_destroy(&full);
    sem_destroy(&mutex);

    return 0;
}