#include <stdio.h>
#include <pthread.h>

void *runner(void *arg) {
    int value = *(int *)arg;   
    printf("Thread received value: %d\n", value);
    return NULL;
}

int main() {
    pthread_t tid;
    int num = 42;

    // Address of num is passed to thread
    pthread_create(&tid, NULL, runner, &num);

    // Ensure main waits so thread can use num safely
    pthread_join(tid, NULL);

    return 0;
}