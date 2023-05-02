#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

#define PIPE_NAME "my_pipe"

int main()
{
    int fd;
    pid_t pid;
    char buf[1024];

    // Create the named pipe
    if (mkfifo(PIPE_NAME, 0666) == -1) {
        perror("mkfifo");
        exit(1);
    }

    // Fork a child process
    if ((pid = fork()) == -1) {
        perror("fork");
        exit(1);
    }

    if (pid == 0) {
        // Child process: read from the pipe
        if ((fd = open(PIPE_NAME, O_RDONLY)) == -1) {
            perror("child: open");
            exit(1);
        }

        while (read(fd, buf, sizeof(buf)) > 0) {
            printf("child: received '%s'\n", buf);
        }

        close(fd);
    } else {
        // Parent process: write to the pipe
        if ((fd = open(PIPE_NAME, O_WRONLY)) == -1) {
            perror("parent: open");
            exit(1);
        }

        printf("parent: sending 'hello'\n");
        write(fd, "hello", 6);

        close(fd);
    }

    return 0;
}

