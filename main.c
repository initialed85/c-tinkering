#include <stdio.h>
#include <stdlib.h>

int main() {
    int *array = NULL;
    int size = 3;

    // Allocate memory for an array of integers
    array = (int *)malloc(size * sizeof(int));
    if (array == NULL) {
        fprintf(stderr, "Memory allocation failed!\n");
        return 1;
    }

    // Initialize the array
    for (int i = 0; i < size; i++) {
        array[i] = i * 10;
    }

    // Print the array
    printf("Original array:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    // Resize the array using realloc
    int new_size = 5;
    int *temp = (int *)realloc(array, new_size * sizeof(int));
    if (temp == NULL) {
        fprintf(stderr, "Memory reallocation failed!\n");
        free(array); // Free the original array before exiting
        return 1;
    }
    array = temp;

    // Initialize the new elements
    for (int i = size; i < new_size; i++) {
        array[i] = i * 10;
    }

    // Print the resized array
    printf("Resized array:\n");
    for (int i = 0; i < new_size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    // Free the allocated memory
    free(array);

    return 0;
}
