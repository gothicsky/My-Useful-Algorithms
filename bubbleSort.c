#include <stdio.h>
// #include <stdlib.h>
// #include <time.h>

#define N 10

int main() {

    int A[N]={5,1,3,4,10,6,23,12,44,13};
    int swapped;

    do {
        swapped = 0;
        for (int i =1, temp; i<N; i++) {
            if (A[i-1]>A[i]) {
                temp = A[i-1];
                A[i-1]=A[i];
                A[i]=temp;
                swapped=1;
            }
        }

    }while (swapped);

    for (int i = 0; i < 10; ++i) {
        printf("%d ", A[i]);
    }

    return 0;
}
