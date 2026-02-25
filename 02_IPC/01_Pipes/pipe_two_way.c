#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main() {
    int fd1[2], fd2[2];
    pipe(fd1);
    pipe(fd2);

    pid_t pid = fork();

    if (pid == 0) {
        close(fd1[1]);
        close(fd2[0]);

        char msg[100];
        read(fd1[0], msg, sizeof(msg));
        printf("Child received: %s\n", msg);

        write(fd2[1], "Hello Parent", 13);
    }
    else {
        close(fd1[0]);
        close(fd2[1]);

        write(fd1[1], "Hello Child", 12);

        char msg[100];
        read(fd2[0], msg, sizeof(msg));
        printf("Parent received: %s\n", msg);
    }

    return 0;
}