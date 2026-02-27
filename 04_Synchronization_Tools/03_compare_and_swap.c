#include <stdio.h>
#include <pthread.h>
#include <stdatomic.h>

atomic_int lock = 0;  // 0 = free, 1 = locked
int counter = 0;

void *process(void *arg) {

    int expected;

    do {
        expected = 0;
    }
    while (!atomic_compare_exchange_strong(&lock, &expected, 1));
    // loop until we successfully change 0 -> 1

    // ---- critical section ----
    counter++;
    printf("Inside CS\n");
    // --------------------------

    atomic_store(&lock, 0);  // release lock
    return NULL;
}

int main() {
    pthread_t t1, t2;

    pthread_create(&t1, NULL, process, NULL);
    pthread_create(&t2, NULL, process, NULL);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    printf("Counter: %d\n", counter);
}