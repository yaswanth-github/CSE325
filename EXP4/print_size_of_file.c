#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

int main(int argc,char *argv[])
{
int fd;
fd=open(argv[1],O_RDONLY);
int size=lseek(fd,0,SEEK_END);

printf("The size of the file %s is %d\n",argv[1],size);
return 0;

}
