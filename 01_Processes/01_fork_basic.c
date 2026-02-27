#include <stdio.h>
#include <unistd.h>

int main() {
    pid_t pid = fork();   // create a child process

    if (pid < 0) {
        printf("Fork failed\n");
    }
    else if (pid == 0) {
        // child process
        printf("Inside Child\n");
        printf("Child PID: %d\n", getpid());
    }
    else {
        // parent process
        printf("Inside Parent\n");
        printf("Parent PID: %d\n", getpid());
    }

    return 0;
}