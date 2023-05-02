#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>

int main(int argc, char *argv[]) {
    DIR *dir;
    struct dirent *ent;
    struct stat st;
    char *dir_name, *largest_file_name = NULL;
    int largest_size = 0;

    if (argc < 2 || (dir = opendir(dir_name = argv[1])) == NULL)
        return printf("Usage: %s directory\n", argv[0]), 1;

    while ((ent = readdir(dir)) != NULL)
        if (stat(ent->d_name, &st) == 0 && S_ISREG(st.st_mode) && st.st_size > largest_size)
            largest_size = st.st_size, largest_file_name = ent->d_name;

    printf("The largest file in directory %s is %s with size %d bytes.\n", dir_name, largest_file_name, largest_size);

    closedir(dir);

    return 0;
}

