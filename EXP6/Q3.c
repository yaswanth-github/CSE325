#include <stdio.h>
#include <pthread.h>

int num_array[] = {4, 7, 2, 8, 1, 5, 6, 3, 9, 10}; // sample array
int num_elements = 10;
double average;
int maximum;
int minimum;

void *calc_average(void *arg) {
    double sum = 0.0;
    for (int i = 0; i < num_elements; i++)
        sum += num_array[i];
    average = sum / num_elements;
    return NULL;
}

void *calc_maximum(void *arg) {
    maximum = num_array[0];
    for (int i = 1; i < num_elements; i++)
        if (num_array[i] > maximum) maximum = num_array[i];
    return NULL;
}

void *calc_minimum(void *arg) {
    minimum = num_array[0];
    for (int i = 1; i < num_elements; i++)
        if (num_array[i] < minimum) minimum = num_array[i];
    return NULL;
}

int main() {
    pthread_t threads[3];
    pthread_create(&threads[0], NULL, calc_average, NULL);
    pthread_create(&threads[1], NULL, calc_maximum, NULL);
    pthread_create(&threads[2], NULL, calc_minimum, NULL);
    for (int i = 0; i < 3; i++)
        pthread_join(threads[i], NULL);
    printf("Average: %.2lf\nMaximum: %d\nMinimum: %d\n", average, maximum, 
minimum);
    return 0;
}

