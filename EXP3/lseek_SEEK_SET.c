#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

int main()
{
int fd;

fd=open("sample.txt",O_RDONLY);
int size=lseek(fd,0,SEEK_END);

int half=size/2;
char buff[half];

lseek(fd,0,SEEK_SET);

read(fd,buff,half);
fd=open("n2.txt",O_CREAT | O_RDWR,0666);
write(fd,buff,half);
return 0;
}
