#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

int main()
{
char buff[15];
read(0,buff,14);
write(1,buff,10);
return 0;
}
