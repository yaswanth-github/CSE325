#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

int main() {
    // Path to your desktop directory
    char* desktop_path = getenv("HOME");
    strcat(desktop_path, "/Desktop");

    // Create a directory on the desktop
    char* dir_name = "my_directory";
    char dir_path[1024];
    snprintf(dir_path, sizeof(dir_path), "%s/%s", desktop_path, dir_name);
    mkdir(dir_path, 0777);

    // Create a file inside the directory
    char* file_name = "my_file.txt";
    char file_path[1024];
    snprintf(file_path, sizeof(file_path), "%s/%s", dir_path, file_name);
    FILE* fp = fopen(file_path, "w");
    fprintf(fp, "Hello, world!\n");
    fclose(fp);

    // List the contents of the directory
    DIR* dir = opendir(dir_path);
    struct dirent* entry;
    while ((entry = readdir(dir)) != NULL) {
        printf("%s\n", entry->d_name);
    }
    closedir(dir);

    return 0;
}

