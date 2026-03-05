#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

sem_t sem;   // counting semaphore

void *task(void *arg) {

    sem_wait(&sem);  // acquire one resource

    printf("Thread %ld entered critical section\n", (long)arg);
    sleep(2);        // simulate using the resource

    printf("Thread %ld leaving critical section\n", (long)arg);

    sem_post(&sem);  // release resource
    return NULL;
}

int main() {

    pthread_t t1, t2, t3, t4;

    // initialize counting semaphore (3 resources available)
    sem_init(&sem, 0, 3);

    pthread_create(&t1, NULL, task, (void*)1);
    pthread_create(&t2, NULL, task, (void*)2);
    pthread_create(&t3, NULL, task, (void*)3);
    pthread_create(&t4, NULL, task, (void*)4);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    pthread_join(t3, NULL);
    pthread_join(t4, NULL);

    sem_destroy(&sem);

    return 0;
}