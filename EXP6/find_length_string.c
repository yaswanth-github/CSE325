#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

// Define a struct to hold the string and the length
typedef struct {
  char *str;
  int len;
} str_len_t;

// Define a thread function that takes a str_len_t pointer as argument
void *find_length(void *arg) {
  // Cast the argument to str_len_t pointer
  str_len_t *sl = (str_len_t *)arg;
  // Find the length of the string using strlen function
  sl->len = strlen(sl->str);
  // Return the pointer as the thread result
  return sl;
}

int main() {
  // Declare an array of strings
  char *strings[] = {"Hello", "World", "This", "Is","Yaswanth"};
  // Declare an array of str_len_t structs
  str_len_t sls[6];
  // Declare an array of pthread_t variables
  pthread_t threads[6];
  // Loop through the strings array
  for (int i = 0; i < 6; i++) {
    // Initialize the str_len_t struct with the string and zero length
    sls[i].str = strings[i];
    sls[i].len = 0;
    // Create a thread and pass the address of the str_len_t struct as argument
    pthread_create(&threads[i], NULL, find_length, &sls[i]);
  }
  // Loop through the threads array
  for (int i = 0; i < 6; i++) {
    // Declare a pointer to hold the thread result
    str_len_t *result;
    // Join the thread and get the result
    pthread_join(threads[i], (void **)&result);
    // Print the string and the length from the result
    printf("%s has length %d\n", result->str, result->len);
  }
  return 0;
}
