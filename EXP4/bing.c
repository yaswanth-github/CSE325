#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <string.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <dirent.h>

int main () {
  // Create a directory on desktop
  char *dirpath = "/users/yaswanth/Desktop/testdir";
  if (mkdir (dirpath, 0755) == -1) {
    perror ("mkdir");
    exit (1);
  }
  printf ("Directory %s created\n", dirpath);

  // Change the current working directory to the new directory
  if (chdir (dirpath) == -1) {
    perror ("chdir");
    exit (1);
  }
  printf ("Current working directory changed to %s\n", dirpath);

  // Create a file inside the directory
  char *filename = "testfile.txt";
  int fd = creat (filename, 0644);
  if (fd == -1) {
    perror ("creat");
    exit (1);
  }
  printf ("File %s created\n", filename);

  // Write some text to the file
  char *text = "This is a test file\n";
  if (write (fd, text, strlen (text)) == -1) {
    perror ("write");
    exit (1);
  }
  printf ("Text written to %s\n", filename);

  // Close the file
  if (close (fd) == -1) {
    perror ("close");
    exit (1);
  }
  printf ("File %s closed\n", filename);

  // Open the directory for reading
  DIR *dp = opendir (".");
  if (dp == NULL) {
    perror ("opendir");
    exit (1);
  }
  printf ("Directory %s opened\n", dirpath);

  // Read and print the contents of the directory
  struct dirent *entry;
  while ((entry = readdir (dp)) != NULL) {
    printf ("%s\n", entry->d_name);
  }

  // Close the directory
  if (closedir (dp) == -1) {
    perror ("closedir");
    exit (1);
  }
  printf ("Directory %s closed\n", dirpath);

  return 0;
}
