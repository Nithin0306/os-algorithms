#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>

int main()
{
    const char *fifo = "myfifo";
    char buffer[100];

    // create named pipe (FIFO file)
    mkfifo(fifo, 0666);

    // open pipe for writing
    int fd = open(fifo, O_WRONLY);

    char message[] = "Hello through Named Pipe";

    // write message into pipe
    write(fd, message, sizeof(message));

    close(fd);

    // open pipe for reading
    fd = open(fifo, O_RDONLY);

    read(fd, buffer, sizeof(buffer));

    printf("Received: %s\n", buffer);

    close(fd);

    return 0;
}