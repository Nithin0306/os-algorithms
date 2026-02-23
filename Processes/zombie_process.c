#include <stdio.h>
#include <unistd.h>

int main() {
    pid_t pid = fork();

    if (pid == 0) {
        printf("Child exiting\n");
    }
    else {
        sleep(2); // Parent not calling wait()
        printf("Parent done\n");
    }

    return 0;
}