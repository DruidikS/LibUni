#include <stdio.h>
#include <stdlib.h>
#include "sorts.h"

int* create_array(int n) {
    int *arr = malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Error memory allocation\n");
        exit(1);
    }
    for (int i = 0; i < n; ++i) {
        arr[i] = rand();
    }
    return arr;
}

void copy_array(int *source, int *dest, int n) {
    for (int i = 0; i < n; ++i) {
        dest[i] = source[i];
    }
}