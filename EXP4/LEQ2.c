#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    // Check that the correct number of arguments were provided
    if (argc != 3) {
        printf("Usage: %s <source_dir> <dest_dir>\n", argv[0]);
        exit(1);
    }

    // Open the source directory
    DIR* src_dir = opendir(argv[1]);
    if (!src_dir) {
        printf("Could not open source directory.\n");
        exit(1);
    }

    // Create the destination directory
    if (mkdir(argv[2], 0777) != 0) {
        printf("Could not create destination directory.\n");
        exit(1);
    }

    // Iterate over the contents of the source directory
    struct dirent* entry;
    while ((entry = readdir(src_dir)) != NULL) {
        // Skip "." and ".." entries
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") 
== 0) {
            continue;
        }

        // Create the full path to the source file
        char src_path[BUFFER_SIZE];
        snprintf(src_path, BUFFER_SIZE, "%s/%s", argv[1], entry->d_name);

        // Create the full path to the destination file
        char dest_path[BUFFER_SIZE];
        snprintf(dest_path, BUFFER_SIZE, "%s/%s", argv[2], entry->d_name);

        // Open the source file for reading
        int src_fd = open(src_path, O_RDONLY);
        if (src_fd < 0) {
            printf("Could not open source file: %s\n", src_path);
            continue;
        }

        // Open the destination file for writing
        int dest_fd = open(dest_path, O_CREAT | O_WRONLY, 0777);
        if (dest_fd < 0) {
            printf("Could not open destination file: %s\n", dest_path);
            close(src_fd);
            continue;
        }

        // Copy the contents of the source file to the destination file
        char buffer[BUFFER_SIZE];
        ssize_t bytes_read;
        while ((bytes_read = read(src_fd, buffer, BUFFER_SIZE)) > 0) {
            ssize_t bytes_written = write(dest_fd, buffer, bytes_read);
            if (bytes_written < 0) {
                printf("Could not write to destination file: %s\n", 
dest_path);
                close(src_fd);
                close(dest_fd);
                continue;
            }
        }

        // Close the source and destination files
        close(src_fd);
        close(dest_fd);
    }

    // Close the source directory
    closedir(src_dir);

    return 0;
}

