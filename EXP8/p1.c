/* The following program illustrates the creation of a child process and data transfer using pipes. */

#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<string.h>
#include<stdlib.h>

int main()
{
 int fd[2],nb;
 pid_t cpid;
 char inf[]="Welcome to LPU\n";
 char rbuff[50];
 pipe(fd);

 if((cpid=fork()) == -1)
 {
 printf("Parent failed to create the child process");
 exit(1);
 }

 if(cpid == 0)
 {
 close(fd[0]);
 write(fd[1],inf,(strlen(inf)+1));
 printf("The information written in the pipe by child is: %s",inf);
 exit(0);
 }

 else
 {
 close(fd[1]);
 nb=read(fd[0],rbuff,sizeof(rbuff));
 printf("The information received by the Parent process from the pipe is:%s",rbuff);
 }

 return(0);
}
