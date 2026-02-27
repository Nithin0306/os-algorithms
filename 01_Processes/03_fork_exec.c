#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid = fork();

    if (pid == 0) {
        // replace child with new program
        execlp("ls", "ls", NULL);
    }
    else {
        wait(NULL);
        printf("Child completed execution\n");
    }

    return 0;
}