#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    char *src_dir = "path/to/source/directory";
    char *original_file = "original_file_name";

    char *mkdir_args[] = {"mkdir", original_file, NULL};
    if (execvp(mkdir_args[0], mkdir_args) == -1) {
        perror("execvp");
        exit(EXIT_FAILURE);
    }

    char *mv_args[] = {"mv", "-v", src_dir, original_file, NULL};
    if (execvp(mv_args[0], mv_args) == -1) {
        perror("execvp");
        exit(EXIT_FAILURE);
    }

    return 0;
}

