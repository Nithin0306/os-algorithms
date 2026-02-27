#include <stdio.h>
#include <pthread.h>

int counter = 0;   // shared variable 

// Both threads run this function
void *increment(void *arg) {

    // Multiple threads update same variable
    // Without synchronization → race condition
    for (int i = 0; i < 100000; i++)
        counter++;

    return NULL;
}

int main() {
    pthread_t t1, t2;

    // Create two threads working on same data
    pthread_create(&t1, NULL, increment, NULL);
    pthread_create(&t2, NULL, increment, NULL);

    // Wait for both threads to finish
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    // Result may vary each run
    printf("Final Counter: %d\n", counter);

    return 0;
}