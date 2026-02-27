#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid = fork();

    if (pid == 0) {
        printf("Child running...\n");
    }
    else {
        wait(NULL);   // parent waits for child to finish
        printf("Parent resumes after child\n");
    }

    return 0;
}