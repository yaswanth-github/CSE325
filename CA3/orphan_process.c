#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include <fcntl.h>

int main()
{
pid_t process; //pid_t is the datatype which stores the processing info
process=fork();

if (process==0)
{

printf("Child Process ID is %d \n", getpid());
printf("Parent Process ID is %d\n", getpid());

}

else
{
printf("I am Parent Process ID %d\n",getpid());
printf("My Child Process ID %d\n",getpid());
}

}
