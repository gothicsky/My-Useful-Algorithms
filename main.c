#include <stdio.h>
// #include <stdlib.h>
// #include <time.h>

#define N 10

int search(const int *arr, int arrSize, int soughtVal) {

    int found=0;
    int upperBound=arrSize-1;
    int middleIndex = arrSize/2;
    int lowerBound=0;

    while (!found && lowerBound<=upperBound) {
        if (arr[middleIndex]>soughtVal) {
            upperBound=middleIndex-1;
        }
        else if (arr[middleIndex]<soughtVal) {
            lowerBound=middleIndex+1;
        }
        else {
            found=1;
        }

        middleIndex = (upperBound+lowerBound)/2;
    }

    return found;
}

int main() {

    int A[N]={1,2,3,4,5,6,7,8,9,10};


    int soughtVal=6;
    int found=0;

    found = search(A, N, soughtVal);

    if (found==1) {
        printf("Found %d", soughtVal);
    }
    else {
        printf("No %d", soughtVal);
    }



    return 0;
}