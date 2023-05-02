#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>

#define MAX_MSG_SIZE 100

struct message_buffer {
    long message_type;
    char message[MAX_MSG_SIZE];
} message;

int main()
{
    key_t key;
    int msgid;

    key = ftok("progfile", 65);
    msgid = msgget(key, 0666 | IPC_CREAT);

    if (fork() == 0) { // Child process (sender)
        message.message_type = 1;
        strcpy(message.message, "Hello, message queue!");
        msgsnd(msgid, &message, sizeof(message), 0);
        exit(0);
    }
    else { // Parent process (receiver)
        msgrcv(msgid, &message, sizeof(message), 1, 0);
        printf("Data received is : %s \n", message.message);
        msgctl(msgid, IPC_RMID, NULL);
        exit(0);
    }
}

