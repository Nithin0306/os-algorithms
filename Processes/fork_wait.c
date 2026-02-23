#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid = fork();

    if (pid == 0) {
        printf("Child executing\n");
    }
    else {
        wait(NULL);
        printf("Parent resumes after child\n");
    }

    return 0;
}