#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "sorts.h"

int main(void) {
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

        printf("| %-10d | %-15f | %-15f | %-15f |\n",
               n, time_bubble, time_insert, time_merge);

        free(base_arr);
        free(temp_arr);
    }

    printf("\n");
    return 0;
}