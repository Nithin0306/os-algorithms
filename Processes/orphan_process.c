#include <stdio.h>
#include <unistd.h>

int main() {
    pid_t pid = fork();

    if (pid == 0) {
        sleep(2);
        printf("Child PPID after parent exit: %d\n", getppid());
    }
    else {
        printf("Parent exiting\n");
    }

    return 0;
}