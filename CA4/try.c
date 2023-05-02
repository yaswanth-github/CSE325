#include "buffer.h"
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <semaphore.h>

/* Create Buffer */
buffer_item buffer[BUFFER_SIZE];

/* Semaphore and Mutex lock */
sem_t cEmpty;
sem_t cFull;
pthread_mutex_t mutex;

/* Threads */
pthread_t tid; /* Thread ID */
pthread_attr_t attr; /* Thread attributes */

void *producer(void *param);
void *consumer(void *param);
void init();

/* Progress Counter */
int cg;

main(int argc, char *argv[])
{
  /* Variables */
  int argarray[3], c1;

  /* Argument counter checks */
  if(argc != 4)
  {
    fprintf(stderr, "usage: main [sleep time] [# of producer threads] [# 
of consumer threads]\n");
    return -1;
  }

  /* Get args from command line and change them into integers */
  argarray[0] = atoi(argv[1]); /* How long to sleep before ending */
  argarray[1] = atoi(argv[2]); /* Producer threads */
  argarray[2] = atoi(argv[3]); /* Consumer threads */

  /* Error check */
  if(argarray[1]<1)
  {
    fprintf(stderr, "argument 2 must be > 0\n");
    return -1;
  }
  if(argarray[2]<1)
  {
    fprintf(stderr, "argument 3 must be > 0\n");
    return -1;
  }    

  init();

  /* Do actual work from this point forward */
  /* Create the producer threads */
  for(c1=1; c1<=argarray[1]; c1++)
  {
    pthread_create(&tid, &attr, producer, NULL);
    printf("Creating producer #%d\n", c1);    
  }

  /* Create the consumer threads */
  for(c1=1; c1<=argarray[2]; c1++)
  {
    pthread_create(&tid, &attr, consumer, NULL);
    printf("Creating consumer #%d\n", c1);    
  }

  /* Ending it */
  sleep(argarray[0]);

  printf("Production complete.\n");
  exit(0);
}

void init()
{
  int c2;

  pthread_mutex_init(&mutex, NULL); /* Initialize mutex lock */
  pthread_attr_init(&attr); /* Initialize pthread attributes to default */
  sem_init(&cFull, 0, 0); /* Initialize full semaphore */
  sem_init(&cEmpty, 0, BUFFER_SIZE); /* Initialize empty semaphore */
  cg = 0; /* Initialize global counter */ 
  for(c2=0;c2<BUFFER_SIZE;c2++) /* Initialize buffer */
  {
    buffer[c2] = 0;
  }
}

void *producer(void *param)
{
  /* Variables */
  buffer_item item;

  while(1)
  { 
    sleep(rand());      
    item = (rand()); /* Generates random item */ 

    sem_wait(&cEmpty); /* Lock empty semaphore if not zero */
    pthread_mutex_lock(&mutex);

    if(insert_item(item))
    {
      fprintf(stderr, "Producer error."); 
    }
    else
    {
      printf("Producer produced %d\n", item); 
    }

    pthread_mutex_unlock(&mutex);
    sem_post(&cFull); /* Increment semaphore for # of full */
  }
}

void *consumer(void *param)
{
  buffer_item item;

  while(1)
  {
    sleep(rand());
    sem_wait(&cFull); /* Lock empty semaphore if not zero */
    pthread_mutex_lock(&mutex);
    if(remove_item(&item))
    {
      fprintf(stderr, "Consumer error."); 
    }
    else
    {
      printf("Consumer consumed %d\n", item);
    }

    pthread_mutex_unlock(&mutex);
    sem_post(&cEmpty); /* Increments semaphore for # of empty */
  }
}

int insert_item(buffer_item item)
{
  if(cg < BUFFER_SIZE) /* Buffer has space */
  {
    buffer[cg] = item;
    cg++;
    return 0;
  }
  else /* Buffer full */
  {
    return -1;
  }
}

int remove_item(buffer_item *item)
{
  if(cg > 0) /* Buffer has something in it */
  {
    *item = buffer[(cg-1)];
    cg--;
    return 0;
  }
  else /* Buffer empty */
  {
    return -1;
  }
}
