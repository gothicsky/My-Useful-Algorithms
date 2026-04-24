#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void populate(int **array, int rows, int columns){
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            array[i][j] = rand()%11;
        }
    }
}

void display(int **array, int rows, int columns){
    for (int i = 0; i < rows; ++i) {
        printf("|");
        for (int j = 0; j < columns; ++j) {
            printf("%d", array[i][j]);
            if (j<columns-1){
                printf(" ");
            }
        }
        printf("|\n");
    }
}

void multiplication(int **A, int **B, int **result, int rows, int columns){
    int sum;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            sum=0;
            for (int k = 0; k < columns; ++k) {
                sum += A[i][k] * B[k][j];
            }
            result[i][j]= sum;
        }
    }
}

int main() {

    srand(time(NULL));

    int **A, **B, **result, rows, columns;

    scanf("%d", &rows);
    scanf("%d", &columns);

    A = (int **)malloc(rows * sizeof(int *));
    B = (int **)malloc(rows * sizeof(int *));
    result = (int **)malloc(rows * sizeof(int *));

    if (A == NULL || B == NULL || result==NULL){
        printf("Allocation failed");
        exit(1);
    }

    for (int i = 0; i < rows; ++i) {
        A[i] = (int *)malloc(columns * sizeof(int));
        B[i] = (int *)malloc(columns * sizeof(int));
        result[i] = (int *)malloc(columns * sizeof(int));
        if (A[i] == NULL || B[i] == NULL || result[i] == NULL){
            printf("[i] Allocation failed");
            exit(1);
        }
    }

    populate(A, rows, columns);
    populate(B, rows, columns);

    display(A, rows, columns);
    printf("\n\n");
    display(B, rows, columns);
    printf("\n\n");
    multiplication(A, B, result, rows, columns);
    display(result, rows, columns);

    for (int i = 0; i < rows; ++i) {
        free (A[i]);
        free (B[i]);
        free (result[i]);
    }

    free(A);
    free(B);
    free(result);

    return 0;
}
