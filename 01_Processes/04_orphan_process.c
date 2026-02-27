#include <stdio.h>
#include <unistd.h>

int main() {
    pid_t pid = fork();

    if (pid == 0) {
        sleep(5);   // wait so parent exits first
        printf("Child new PPID: %d\n", getppid());  // adopted by init
    }
    else {
        printf("Parent exiting...\n");
    }

    return 0;
}