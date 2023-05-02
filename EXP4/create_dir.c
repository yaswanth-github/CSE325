#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>

int main(int argc, char *argv[])
{
int dir;
dir=mkdir(argv[1],0777);
return 0;
}
