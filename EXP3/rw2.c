#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

int main()
{
int fd;
char buff[50];
fd=open("sample.txt",O_RDONLY);
read(fd,buff,45);
write(1,buff,30);
return 0;
}
