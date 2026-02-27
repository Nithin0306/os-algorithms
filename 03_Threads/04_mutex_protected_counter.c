#include <stdio.h>
#include <pthread.h>

int counter = 0;                    // shared variable
pthread_mutex_t lock;               // mutex to protect counter

void *increment(void *arg) {

    for (int i = 0; i < 5; i++) {  

        pthread_mutex_lock(&lock);   // enter critical section

        counter++;                   // safe update

        printf("Counter updated to: %d\n", counter);

        pthread_mutex_unlock(&lock); // leave critical section
    }

    return NULL;
}

int main() {
    pthread_t t1, t2;

    // initialize mutex before use
    pthread_mutex_init(&lock, NULL);

    pthread_create(&t1, NULL, increment, NULL);
    pthread_create(&t2, NULL, increment, NULL);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    printf("Final Counter: %d\n", counter);

    // clean up mutex
    pthread_mutex_destroy(&lock);
    return 0;
}