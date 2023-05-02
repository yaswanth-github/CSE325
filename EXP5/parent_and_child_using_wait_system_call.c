#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>

int main()
{
pid_t pid;
int status;
pid=fork();

if(pid==-1)
{
printf("Error: Faild to fork process\n");
}

else if(pid==0)
{
printf("Child Process Running.\n");
sleep(10);
printf("Child Process Exiting.\n");
exit(0);
}
else
{
printf("Parent process waiting for child process...\n");
wait(&status);
printf("Child Process exited with status %d.\n",status);
}

return 0;
}
