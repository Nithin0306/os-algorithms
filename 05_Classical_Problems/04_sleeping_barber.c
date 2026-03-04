#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define CHAIRS 3

sem_t customers;   // number of waiting customers
sem_t barber;      // barber ready
sem_t mutex;       // protect shared data

int waiting = 0;

void *barber_thread(void *arg) {

    while (1) {

        sem_wait(&customers);     // wait for customer

        sem_wait(&mutex);
        waiting--;                // one customer moves to barber chair
        sem_post(&barber);        // barber ready
        sem_post(&mutex);

        printf("Barber cutting hair...\n");
        sleep(2);
    }
}

void *customer_thread(void *arg) {

    sem_wait(&mutex);

    if (waiting < CHAIRS) {

        waiting++;
        printf("Customer waiting. Waiting count: %d\n", waiting);

        sem_post(&customers);   // notify barber
        sem_post(&mutex);

        sem_wait(&barber);      // wait until barber ready
        printf("Customer getting haircut\n");
    }
    else {

        sem_post(&mutex);
        printf("Customer leaving (no free chairs)\n");
    }

    return NULL;
}

int main() {

    pthread_t barber;
    pthread_t customers_thread[5];

    sem_init(&customers, 0, 0);
    sem_init(&barber, 0, 0);
    sem_init(&mutex, 0, 1);

    pthread_create(&barber, NULL, barber_thread, NULL);

    for (int i = 0; i < 5; i++) {
        sleep(1);
        pthread_create(&customers_thread[i], NULL, customer_thread, NULL);
    }

    pthread_join(barber, NULL);

    return 0;
}