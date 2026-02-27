#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>

int main() {
    int shmid = shmget(IPC_PRIVATE, 1024, 0666 | IPC_CREAT);
    char *data = (char *)shmat(shmid, NULL, 0);

    pid_t pid = fork();

    if (pid == 0) {
        sleep(1);
        printf("Child reads: %s\n", data);
    }
    else {
        sprintf(data, "Hello from Parent");
    }

    return 0;
}