#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>

int main() {
    int shmid = shmget(IPC_PRIVATE, 1024, 0666 | IPC_CREAT);
    char *data = (char *)shmat(shmid, NULL, 0);

    sprintf(data, "Shared memory example");
    printf("Data written: %s\n", data);

    shmdt(data);                 // detach
    shmctl(shmid, IPC_RMID, 0);  // remove segment

    return 0;
}