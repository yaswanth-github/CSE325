//to hold arguments to the thread function

#include<stdio.h>
#include<pthread.h>

struct thread_args
{
int arg1;
int arg2;
char *arg3;
};

void *my_thread_func(void *arg)
{
struct thread_args *my_args=(struct thread_args *)arg;
printf("arg1=%d\n", my_args->arg1);
printf("arg2=%d\n", my_args->arg2);
printf("arg3=%s\n", my_args->arg3);
pthread_exit(NULL);
}

int main()
{
pthread_t my_thread;
struct thread_args my_args={5,80,"K21CH"};
pthread_create(&my_thread,NULL,my_thread_func,(void *)&my_args);
pthread_join(my_thread,NULL);
return 0;
}
