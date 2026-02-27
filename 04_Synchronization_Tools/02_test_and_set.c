#include <stdio.h>
#include <pthread.h>
#include <stdatomic.h>

atomic_flag lock = ATOMIC_FLAG_INIT;  // simple spinlock
int counter = 0;

void *process(void *arg) {

    // keep trying until lock is acquired
    while (atomic_flag_test_and_set(&lock));

    // ---- critical section ----
    counter++;
    printf("Inside CS\n");
    // --------------------------

    atomic_flag_clear(&lock);  // release lock
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