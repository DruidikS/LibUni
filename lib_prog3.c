#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main() {
    int N, M;

    printf("Enter str N ");
    if (scanf("%d", &N) != 1 || N <= 0) {
        printf("Eror enter data\n");
        return 1;
    }

    printf("Enter stolb M ");
    if (scanf("%d", &M) != 1 || M <= 0) {
        printf("Eror enter data\n");
        return 1;
    }

    int **A = (int **)malloc(N * sizeof(int *));
    if (A == NULL) {
        printf("Error\n");
        return 1;
    }
    for (int i = 0; i < N; i++) {
        A[i] = (int *)malloc(M * sizeof(int));
        if (A[i] == NULL) {
            printf("Out of memory error\n");
            for (int k = 0; k < i; k++) free(A[k]);
            free(A);
            return 1;
        }
    }

    printf("Enter elments (%d x %d):\n", N, M);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            printf("A[%d][%d] = ", i, j);
            if (scanf("%d", &A[i][j]) != 1) {
                printf("Error enter element\n");
                for (int k = 0; k < N; k++) free(A[k]);
                free(A);
                return 1;
            }
        }
    }

    int *B = (int *)malloc(N * sizeof(int));
    if (B == NULL) {
        printf("Out of memory error\n");
        for (int i = 0; i < N; i++) free(A[i]);
        free(A);
        return 1;
    }

    for (int i = 0; i < N; i++) {
        int minVal = A[i][0];
        for (int j = 1; j < M; j++) {
            if (A[i][j] < minVal) minVal = A[i][j];
        }
        B[i] = minVal;
    }

    printf("\nArray min elements:\n");
    for (int i = 0; i < N; i++) {
        printf("B[%d] = %d\n", i, B[i]);
    }


    long long P = 1;
    int overflowFlag = 0;
    for (int i = 0; i < N; i++) {

        if (B[i] != 0) {
            if (P > 0 && B[i] > 0 && P > LLONG_MAX / B[i]) { overflowFlag = 1; break; }
            if (P < 0 && B[i] < 0 && P < LLONG_MAX / B[i]) { overflowFlag = 1; break; }
            if (P > 0 && B[i] < 0 && B[i] < LLONG_MIN / P) { overflowFlag = 1; break; }
            if (P < 0 && B[i] > 0 && P < LLONG_MIN / B[i]) { overflowFlag = 1; break; }
        }
        P *= B[i];
    }

    if (overflowFlag) {
        printf("\nerror big number\n");
    }
    printf("\nP = %lld\n", P);

    for (int i = 0; i < N; i++) {
        int minIdx = 0;
        for (int j = 1; j < M; j++) {
            if (A[i][j] < A[i][minIdx]) minIdx = j;
        }
        A[i][minIdx] = (int)P;
    }

    printf("\nArray and P:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            printf("%6d ", A[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < N; i++) free(A[i]);
    free(A);
    free(B);

    return 0;
}