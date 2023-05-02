//to perform fatorial and evalutuate even odd using threads

#include<stdio.h>
#include<pthread.h>

void *factorial(void *temp1)
{
int *x=(int *)temp1;
int i, fact=1;

for(i=1;i<=*x;i++)
fact=fact*i;
printf("Factoril is : %d\n",fact);
return NULL;
 

void *even_odd(void *temp2)
{
int *y=(int *)temp2;
int ret;
ret=*y%2;

if(ret==0)
printf("NUMBER IS EVEN\n");}
else
printf("NUMBER IS ODD\n");
return NULL;
}

int main()
{
int n;
scanf("%d",&n);
pthread_t thread1,thread2;

pthread_create(&thread1,NULL,factorial,(void *)&n);
pthread_create(&thread1,NULL,even_odd,(void *)&n);
pthread_join(thread1,NULL);
pthread_join(thread2,NULL);
return 0;
}
