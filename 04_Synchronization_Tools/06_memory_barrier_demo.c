#include <stdio.h>
#include <pthread.h>
#include <stdatomic.h>

atomic_int x = 0;
atomic_bool flag = 0;

void *writer(void *arg) {
    atomic_store(&x, 100);     // write data
    atomic_thread_fence(memory_order_seq_cst); // memory barrier
    atomic_store(&flag, 1);    // then set flag
    return NULL;
}

void *reader(void *arg) {

    while (!atomic_load(&flag));  // wait for flag

    atomic_thread_fence(memory_order_seq_cst);

    printf("x = %d\n", atomic_load(&x));
    return NULL;
}

int main() {
    pthread_t t1, t2;

    pthread_create(&t1, NULL, writer, NULL);
    pthread_create(&t2, NULL, reader, NULL);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
}