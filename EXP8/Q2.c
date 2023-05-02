// include the necessary header files

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <mqueue.h>

// define the name of the message queue
#define QUEUE_NAME "/my_queue"
// define the maximum size of the message
#define MAX_SIZE 1024
// define the exit message
#define EXIT_MSG "exit"

// define the main function
int main() {
  // declare a message queue descriptor
  mqd_t mq;
  // declare a buffer to hold the message
  char buffer[MAX_SIZE + 1];
  // declare a variable to hold the message priority
  unsigned int priority;
  // declare a struct to hold the message queue attributes
  struct mq_attr attr;
  // set the maximum number of messages and the maximum size of each 
message
  attr.mq_maxmsg = 10;
  attr.mq_msgsize = MAX_SIZE;

  // open or create the message queue with read-write permissions
  mq = mq_open(QUEUE_NAME, O_CREAT | O_RDWR, 0644, &attr);
  // check if the message queue was opened successfully
  if (mq == -1) {
    // print an error message and exit
    perror("mq_open");
    exit(1);
  }

  // loop until the exit message is received
  do {
    // receive a message from the queue and store it in the buffer
    ssize_t bytes_read = mq_receive(mq, buffer, MAX_SIZE, &priority);
    // check if the message was received successfully
    if (bytes_read == -1) {
      // print an error message and exit
      perror("mq_receive");
      exit(1);
    }
    // add a null terminator to the buffer
    buffer[bytes_read] = '\0';
    // print the received message and its priority
    printf("Received: %s (priority: %u)\n", buffer, priority);
    // send a reply message to the queue with the same priority
    if (mq_send(mq, buffer, strlen(buffer), priority) == -1) {
      // print an error message and exit
      perror("mq_send");
      exit(1);
    }
    // print the sent message and its priority
    printf("Sent: %s (priority: %u)\n", buffer, priority);
  } while (strcmp(buffer, EXIT_MSG) != 0);

  // close the message queue
  if (mq_close(mq) == -1) {
    // print an error message and exit
    perror("mq_close");
    exit(1);
  }

  // unlink the message queue
  if (mq_unlink(QUEUE_NAME) == -1) {
    // print an error message and exit
    perror("mq_unlink");
    exit(1);
  }

  // return 0 to indicate success
  return 0;
}
