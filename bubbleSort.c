#include <stdio.h>
#include <stdlib.h>

#define N 10

int* bubble_sort_safe(int arr[], int arrSize) {

    int* sortedArray = (int *)malloc(arrSize * sizeof(int));

    if (sortedArray==NULL) {
        exit(1);
    }

    for (int i=0; i<arrSize; i++) {
        sortedArray[i]=arr[i];
    }


    int swapped;
    do {
        swapped = 0;
        for (int i =1, temp; i<arrSize; i++) {
            if (sortedArray[i-1]>sortedArray[i]) {
                temp = sortedArray[i-1];
                sortedArray[i-1]=sortedArray[i];
                sortedArray[i]=temp;
                swapped=1;
            }
        }

    }while (swapped);

    return sortedArray;
}

void bubble_sort(int *arr, int arrSize) {
    int swapped;
    do {
        swapped = 0;
        for (int i =1, temp; i<arrSize; i++) {
            if (arr[i-1]>arr[i]) {
                temp = arr[i-1];
                arr[i-1]=arr[i];
                arr[i]=temp;
                swapped=1;
            }
        }

    }while (swapped);
}

int main() {

    int A[N]={5,1,3,4,10,6,23,12,44,13};

    //returns a new array
    // int* B = bubble_sort_safe(A, N);
    // for (int i = 0; i < 10; ++i) {
    //     printf("%d ", B[i]);
    // }
    // free(B);


    //changes the array
    // bubble_sort(A, N);
    // for (int i = 0; i < 10; ++i) {
    //     printf("%d ", A[i]);
    // }



    return 0;
}
