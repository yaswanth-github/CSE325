//to print the values in an array using threads

#include<stdio.h>
#include<pthread.h>

void *my_thread_func(void *arg)
{
int *p=(int*)arg;
printf("%d\n",p[4]);
pthread_exit(NULL);
}

int main()
{
pthread_t my_thread;
int array[10]={0,1,2,3,4,5,6,7,8,9};
pthread_create(&my_thread,NULL,my_thread_func, (void *)array);
pthread_join(my_thread,NULL);
return 0;
}
