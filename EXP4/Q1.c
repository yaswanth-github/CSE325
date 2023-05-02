#include<stdio.h>
#include<string.h>
#include<sys/types.h>
#include<unistd.h>
#include<dirent.h>
#include<stdlib.h>
#include<sys/stat.h>
#include<fcntl.h>


int main()
{

char* dirname="Directory";
int check;
char dir_path[1024];
check = mkdir(dirname,0777);

// Create a file inside the directory
char* file_name = "new_file.txt";


// List the contents of the directory
struct dirent* entry;
DIR* dir = opendir(dirname);
while ((entry = readdir(dir)) != NULL)
{
printf("%s\n", entry->d_name);
}
closedir(dir);

return 0;
}
