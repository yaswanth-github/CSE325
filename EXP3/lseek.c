#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

int main()
{
int fd;
char buff[15];
fd=open("sample.txt",O_RDONLY);
lseek(fd,-10,SEEK_END);
read(fd,buff,10);
fd=open("n1.txt",O_CREAT | O_RDWR,0666);
write(fd,buff,10);
return 0;
}
