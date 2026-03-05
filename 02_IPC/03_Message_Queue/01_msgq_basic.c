#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <mqueue.h>

int main() {

    mqd_t mq;              // message queue descriptor
    char buffer[100];      // buffer for received message

    struct mq_attr attr;   // queue attributes

    // configure queue properties
    attr.mq_flags = 0;        // blocking mode
    attr.mq_maxmsg = 10;      // max messages in queue
    attr.mq_msgsize = 100;    // max size of each message
    attr.mq_curmsgs = 0;

    // create/open POSIX message queue
    mq = mq_open("/myqueue", O_CREAT | O_RDWR, 0666, &attr);

    // send a message into the queue
    mq_send(mq, "Hello POSIX Queue", 18, 0);

    // receive message from the queue
    mq_receive(mq, buffer, 100, NULL);

    printf("Received: %s\n", buffer);

    mq_close(mq);           // close queue descriptor
    mq_unlink("/myqueue");  // remove queue from system

    return 0;
}