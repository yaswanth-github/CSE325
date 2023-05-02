#include <stdio.h>
#include <pthread.h>

#define ARRAY_SIZE 10

int int_array[ARRAY_SIZE] = {5, 7, 2, 8, 1, 4, 6, 3, 9, 10};

void *sort_array(void *arg) {
    int *sub_array = arg;
    int i, j, temp;
    for (i = 0; i < ARRAY_SIZE/2 - 1; i++) {
        for (j = 0; j < ARRAY_SIZE/2 - i - 1; j++) {
            if (sub_array[j] > sub_array[j+1]) {
                temp = sub_array[j];
                sub_array[j] = sub_array[j+1];
                sub_array[j+1] = temp;
            }
        }
    }
    pthread_exit(NULL);
}

void *merge_and_sort(void *arg) {
    int i = 0, j = 0, k = 0;
    int merged_array[ARRAY_SIZE];
    int *sub_array1 = int_array;
    int *sub_array2 = int_array + ARRAY_SIZE/2;
    while (i < ARRAY_SIZE/2 && j < ARRAY_SIZE/2) {
        if (sub_array1[i] <= sub_array2[j]) {
            merged_array[k] = sub_array1[i];
            i++;
        } else {
            merged_array[k] = sub_array2[j];
            j++;
        }
        k++;
    }
    while (i < ARRAY_SIZE/2) {
        merged_array[k] = sub_array1[i];
        i++;
        k++;
    }
    while (j < ARRAY_SIZE/2) {
        merged_array[k] = sub_array2[j];
        j++;
        k++;
    }
    for (i = 0; i < ARRAY_SIZE; i++) {
        int_array[i] = merged_array[i];
    }
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[3];
    int i;
    pthread_create(&threads[0], NULL, sort_array, int_array);
    pthread_create(&threads[1], NULL, sort_array, int_array + 
ARRAY_SIZE/2);
    pthread_join(threads[0], NULL);
    pthread_join(threads[1], NULL);
    pthread_create(&threads[2], NULL, merge_and_sort, NULL);
    pthread_join(threads[2], NULL);
    printf("Sorted array:\n");
    for (i = 0; i < ARRAY_SIZE; i++) {
        printf("%d ", int_array[i]);
    }
    printf("\n");
    return 0;
}

