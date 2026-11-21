#include <stdlib.h>
#include "sorts.h"

static void merge(int *arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int *temp_L = malloc(n1 * sizeof(int));
    int *temp_R = malloc(n2 * sizeof(int));

    for (int i = 0; i < n1; ++i) {
        temp_L[i] = arr[left + i];
    }
    for (int j = 0; j < n2; ++j) {
        temp_R[j] = arr[mid + 1 + j];
    }

    int i = 0;
    int j = 0;
    int k = left;

    while (i < n1 && j < n2) {
        if (temp_L[i] <= temp_R[j]) {
            arr[k] = temp_L[i];
            ++i;
        } else {
            arr[k] = temp_R[j];
            ++j;
        }
        ++k;
    }

    while (i < n1) {
        arr[k] = temp_L[i];
        ++i;
        ++k;
    }
    while (j < n2) {
        arr[k] = temp_R[j];
        ++j;
        ++k;
    }

    free(temp_L);
    free(temp_R);
}

void merge_sort(int *arr, int left, int right) {
    if (left < right) {
        int mid = (left + right) / 2;

        merge_sort(arr, left, mid);
        merge_sort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}