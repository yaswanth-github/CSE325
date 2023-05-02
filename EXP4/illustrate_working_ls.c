#include<unistd.h>
#include<stdio.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<dirent.h>

int main()
{
DIR *dp;
struct dirent *direntPt;
dp=opendir("Chinni/Pics");

while((direntPt=readdir(dp))!=NULL)
{
	printf("%s\n",direntPt->d_name);
}
closedir(dp);
return 0;
}
