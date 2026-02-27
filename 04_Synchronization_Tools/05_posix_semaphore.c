#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

sem_t sem;   // binary semaphore

void *task(void *arg) {

    sem_wait(&sem);  // wait until resource is free

    printf("Inside Critical Section\n");

    sem_post(&sem);  // release
    return NULL;
}

int main() {
    pthread_t t1, t2;

    sem_init(&sem, 0, 1);  // 1 means available

    pthread_create(&t1, NULL, task, NULL);
    pthread_create(&t2, NULL, task, NULL);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    sem_destroy(&sem);
}