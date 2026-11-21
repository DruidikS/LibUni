#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void bubble_sort(int *arr, int n){

        for (int i = 0; i < n - 1; ++i){
                int swapped = 0;
                for (int j = 0; j < n - i - 1; ++j){
                        if (arr[j] > arr[j + 1]){
                                int temp = arr[j];
                                arr[j] = arr[j + 1];
                                arr[j + 1] = temp;
                                swapped = 1;
                        }
                }
                if (!swapped) break;
        }

}

void insert_sort(int *arr, int n){

        for (int i = 1; i < n; ++i){
                int key = arr[i];
                int j = i - 1;
                while(j >= 0 && arr[j] > key){
                        arr[j + 1] = arr[j];
                        --j;
                }
                arr[j + 1] = key;
        }

}

void merge(int *arr, int left, int mid, int right) {
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

int main(){

        int sizes[4] = {10, 1000, 10000, 100000};
            srand((unsigned int)time(NULL));

        printf("            sorting execution time(in seconds)              \n");
            printf("-----------------------------------------------------------------\n");
            printf("| Size       | Bubble          | Insertion      | Merge           |\n");
            printf("-----------------------------------------------------------------\n");

            for (int s = 0; s < 4; ++s) {
                int n = sizes[s];

                int *base_arr = create_array(n);
                int *temp_arr = malloc(n * sizeof(int));
                if (temp_arr == NULL) {
                    printf("Error memory allocation\n");
                    exit(1);
                }

                clock_t start, end;

                copy_array(base_arr, temp_arr, n);
        start = clock();
        bubble_sort(temp_arr, n);
        end = clock();
        double time_bubble = (double)(end - start) / CLOCKS_PER_SEC;

        copy_array(base_arr, temp_arr, n);
        start = clock();
        insert_sort(temp_arr, n);
        end = clock();
        double time_insert = (double)(end - start) / CLOCKS_PER_SEC;

        copy_array(base_arr, temp_arr, n);
        start = clock();
        merge_sort(temp_arr, 0, n - 1);
        end = clock();
        double time_merge = (double)(end - start) / CLOCKS_PER_SEC;

        printf("| %-10d | %-15f | %-15f | %-15f |\n", n, time_bubble, time_insert, time_merge);

                free(base_arr);
                free(temp_arr);
            }

        printf("\n");
        return 0;

}