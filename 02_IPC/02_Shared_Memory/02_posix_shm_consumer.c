#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <unistd.h>

#define SIZE 4096
#define NAME "/os_shared_mem"

int main() {

    int shm_fd;
    char *ptr;

    // open existing shared memory
    shm_fd = shm_open(NAME, O_RDONLY, 0666);

    // map shared memory
    ptr = mmap(0, SIZE, PROT_READ, MAP_SHARED, shm_fd, 0);

    // read message
    printf("Consumer read: %s\n", ptr);

    // remove shared memory object
    shm_unlink(NAME);

    return 0;
}