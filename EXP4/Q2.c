#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>

// Function to copy the contents of the source directory to the 
destination directory
void copy_dir(const char *src_dir, const char *dst_dir) {
    DIR *dir;
    struct dirent *entry;
    struct stat st;
    char src_path[1024], dst_path[1024];

    // Create the destination directory if it does not exist
    if (mkdir(dst_dir, 0755) != 0 && errno != EEXIST) {
        perror("mkdir");
        exit(EXIT_FAILURE);
    }

    // Open the source directory
    if ((dir = opendir(src_dir)) == NULL) {
        perror("opendir");
        exit(EXIT_FAILURE);
    }

    // Loop through the entries in the source directory
    while ((entry = readdir(dir)) != NULL) {
        // Skip the "." and ".." entries
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") 
== 0) {
            continue;
        }

        // Build the paths to the source and destination items
        snprintf(src_path, sizeof(src_path), "%s/%s", src_dir, 
entry->d_name);
        snprintf(dst_path, sizeof(dst_path), "%s/%s", dst_dir, 
entry->d_name);

        // Get information about the source item
        if (lstat(src_path, &st) != 0) {
            perror("lstat");
            exit(EXIT_FAILURE);
        }

        // Copy the source item to the destination
        if (S_ISDIR(st.st_mode)) {
            // If the source item is a directory, copy it recursively
            copy_dir(src_path, dst_path);
        } else {
            // If the source item is a file, copy it
            FILE *src_file, *dst_file;
            char buffer[4096];
            size_t n;

            if ((src_file = fopen(src_path, "rb")) == NULL) {
                perror("fopen");
                exit(EXIT_FAILURE);
            }

            if ((dst_file = fopen(dst_path, "wb")) == NULL) {
                perror("fopen");
                exit(EXIT_FAILURE);
            }

            while ((n = fread(buffer, 1, sizeof(buffer), src_file)) > 0) {
                fwrite(buffer, 1, n, dst_file);
            }

            fclose(src_file);
            fclose(dst_file);
        }
    }

    // Close the source directory
    closedir(dir);
}

// Example usage
int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <src_dir> <dst_dir>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    copy_dir(argv[1], argv[2]);

    return EXIT_SUCCESS;
}

