#include<stdio.h>
#include<pthread.h>

int shared=5;
void *func1()
{
int local;
/*critical section */
local=shared;
local=local+1;
sleep(5);
/* causes a context switch */
printf("shared in funct1: %d\n",shared);
pthread_exit(NULL);
}

void *func2()
{
int local;
/*critical section*/
local=shared;
local=local+1;
shared=local;
/*critical section*/
printf("shared in func2: %d\n",shared);
pthread_exit(NULL);
}

int main()
{
pthread_t t1,t2;
pthread_create(&t1,NULL,func1,NULL);
pthread_create(&t2,NULL,func1,NULL);
pthread_join(t1,NULL);
pthread_join(t2,NULL);
}
