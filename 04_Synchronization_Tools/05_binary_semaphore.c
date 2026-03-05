#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

sem_t sem;   // binary semaphore

void *task(void *arg) {

    sem_wait(&sem);  // acquire semaphore

    printf("Thread entered critical section\n");
    sleep(1);        // simulate work

    printf("Thread leaving critical section\n");

    sem_post(&sem);  // release semaphore
    return NULL;
}

int main() {

    pthread_t t1, t2;

    // initialize binary semaphore (value = 1)
    sem_init(&sem, 0, 1);

    pthread_create(&t1, NULL, task, NULL);
    pthread_create(&t2, NULL, task, NULL);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    sem_destroy(&sem);

    return 0;
}