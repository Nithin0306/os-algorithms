#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

// semaphore to protect read_count updates
sem_t mutex;

// semaphore to control access to shared data
sem_t rw_mutex;

int read_count = 0;   // number of readers currently reading
int data = 0;         // shared resource

void *reader(void *arg)
{
    // reader wants to enter
    sem_wait(&mutex);
    read_count++;

    // if this is the first reader, block writers
    if (read_count == 1)
        sem_wait(&rw_mutex);

    sem_post(&mutex);

    // critical section (reading shared data)
    printf("Reader %ld reads data = %d\n", (long)arg, data);
    sleep(1);   // simulate reading time

    // reader leaving
    sem_wait(&mutex);
    read_count--;

    // if this was the last reader, allow writers
    if (read_count == 0)
        sem_post(&rw_mutex);

    sem_post(&mutex);

    return NULL;
}

void *writer(void *arg)
{
    // writer waits until resource is free
    sem_wait(&rw_mutex);

    // critical section (writing to shared data)
    data++;
    printf("Writer %ld writes data = %d\n", (long)arg, data);
    sleep(1);   // simulate writing time

    // release resource
    sem_post(&rw_mutex);

    return NULL;
}

int main()
{
    pthread_t r[3], w[2];  // 3 readers, 2 writers

    // initialize semaphores
    sem_init(&mutex, 0, 1);
    sem_init(&rw_mutex, 0, 1);

    // create reader threads
    for (long i = 0; i < 3; i++)
        pthread_create(&r[i], NULL, reader, (void*)i);

    // create writer threads
    for (long i = 0; i < 2; i++)
        pthread_create(&w[i], NULL, writer, (void*)i);

    // wait for readers to finish
    for (int i = 0; i < 3; i++)
        pthread_join(r[i], NULL);

    // wait for writers to finish
    for (int i = 0; i < 2; i++)
        pthread_join(w[i], NULL);

    // destroy semaphores
    sem_destroy(&mutex);
    sem_destroy(&rw_mutex);

    return 0;
}