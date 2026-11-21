#ifndef SORTS_H
#define SORTS_H

void bubble_sort(int *arr, int n);

void insert_sort(int *arr, int n);

void merge_sort(int *arr, int left, int right);

int* create_array(int n);
void copy_array(int *source, int *dest, int n);

#endif