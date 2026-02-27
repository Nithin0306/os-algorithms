#include <stdio.h>
#include <pthread.h>

void *runner(void *arg) {
    printf("Thread is running\n");
    return NULL;
}

int main() {
    pthread_t tid;   // thread identifier

    // Create a new thread that runs runner()
    pthread_create(&tid, NULL, runner, NULL);

    // Wait for the thread to finish before exiting main
    pthread_join(tid, NULL);

    printf("Main thread exiting\n");
    return 0;
}