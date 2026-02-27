#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main() {
    int fd[2];
    pipe(fd);   // create pipe

    pid_t pid = fork();

    if (pid == 0) {
        close(fd[1]);  // close write end
        char buffer[100];
        read(fd[0], buffer, sizeof(buffer));
        printf("Child received: %s\n", buffer);
    }
    else {
        close(fd[0]);  // close read end
        char msg[] = "Hello Child";
        write(fd[1], msg, strlen(msg) + 1);
    }

    return 0;
}