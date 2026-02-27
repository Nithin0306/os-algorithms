#include <stdio.h>
#include <pthread.h>
#include <stdbool.h>

int turn;              // whose turn to enter CS
bool flag[2];          // indicates interest
int counter = 0;

void *process(void *arg) {
    int i = *(int *)arg;      // current process id (0 or 1)
    int j = 1 - i;            // other process

    flag[i] = true;           // i wants to enter
    turn = j;                 // give chance to other first

    // wait while other wants and it's their turn
    while (flag[j] && turn == j);

    // ---- critical section ----
    counter++;
    printf("Process %d entered CS\n", i);
    // --------------------------

    flag[i] = false;          // done with CS
    return NULL;
}

int main() {
    pthread_t t0, t1;
    int id0 = 0, id1 = 1;

    pthread_create(&t0, NULL, process, &id0);
    pthread_create(&t1, NULL, process, &id1);

    pthread_join(t0, NULL);
    pthread_join(t1, NULL);

    printf("Final Counter: %d\n", counter);
    return 0;
}