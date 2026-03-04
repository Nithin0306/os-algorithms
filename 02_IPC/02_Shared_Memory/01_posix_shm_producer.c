#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>      // O_CREAT, O_RDWR
#include <sys/mman.h>   // shm_open, mmap
#include <unistd.h>

#define SIZE 4096
#define NAME "/os_shared_mem"

int main() {

    int shm_fd;
    char *ptr;

    // create shared memory object
    shm_fd = shm_open(NAME, O_CREAT | O_RDWR, 0666);

    // set memory size
    ftruncate(shm_fd, SIZE);

    // map memory into address space
    ptr = mmap(0, SIZE, PROT_WRITE, MAP_SHARED, shm_fd, 0);

    // write message
    sprintf(ptr, "Hello from POSIX Producer");

    printf("Producer wrote to shared memory\n");

    return 0;
}