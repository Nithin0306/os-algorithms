#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>      // shm_open
#include <sys/mman.h>   // mmap
#include <unistd.h>
#include <sys/wait.h>

#define SIZE 4096
#define NAME "/os_shm"

int main() {

    int shm_fd;
    char *ptr;

    // create shared memory
    shm_fd = shm_open(NAME, O_CREAT | O_RDWR, 0666);

    // set memory size
    ftruncate(shm_fd, SIZE);

    // map shared memory into address space
    ptr = mmap(0, SIZE, PROT_WRITE | PROT_READ, MAP_SHARED, shm_fd, 0);

    pid_t pid = fork();   // create child process

    if (pid == 0) {
        // child process reads from shared memory
        sleep(1); // wait for parent to write
        printf("Child read: %s\n", ptr);
    }
    else {
        // parent writes into shared memory
        sprintf(ptr, "Hello from Parent via POSIX Shared Memory");

        wait(NULL);  // wait for child
        shm_unlink(NAME); // remove shared memory object
    }

    return 0;
}