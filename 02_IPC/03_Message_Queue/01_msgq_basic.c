#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>

struct message {
    long type;
    char text[100];
};

int main() {
    int msgid = msgget(IPC_PRIVATE, 0666 | IPC_CREAT);

    struct message msg;
    msg.type = 1;
    strcpy(msg.text, "Hello Message Queue");

    msgsnd(msgid, &msg, sizeof(msg.text), 0);
    msgrcv(msgid, &msg, sizeof(msg.text), 1, 0);

    printf("Received: %s\n", msg.text);

    msgctl(msgid, IPC_RMID, NULL);  // remove queue
    return 0;
}