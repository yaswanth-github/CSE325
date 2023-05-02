#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>

int main()
{

pid_t pid=getpid(); // pid_t will store the processing info.

printf("The Current Process pid is %d\n", pid);
printf("Forking a child process..");
pid_t child_pid=fork();

if (child_pid==-1)
{
printf("Faild to fork a child process.\n");
}

else if (child_pid==0)
{
printf("chil process pid is %d, parent pid is %d\n",getpid(),getppid());
}

else
{
printf("Parent process pid: %d\n", getpid());
}

return 0;
}
