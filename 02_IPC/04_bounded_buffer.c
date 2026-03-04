#include <stdio.h>

#define BUFFER_SIZE 10

int buffer[BUFFER_SIZE];
int in = 0;
int out = 0;

void produce(int item) {

    while (((in + 1) % BUFFER_SIZE) == out)
        ;   // wait if buffer is full

    buffer[in] = item;
    in = (in + 1) % BUFFER_SIZE;
}

int consume() {

    while (in == out)
        ;   // wait if buffer empty

    int item = buffer[out];
    out = (out + 1) % BUFFER_SIZE;

    return item;
}

int main() {

    produce(10);
    produce(20);

    printf("Consumed: %d\n", consume());
    printf("Consumed: %d\n", consume());

    return 0;
}