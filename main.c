#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 800

void eratosthenes(int arr[])
{
    for (int i = 2; i < N; ++i)
    {
        for (int j = i+1; j < N; ++j)
        {
            if (j%i==0)
            {
                arr[j]=0;
            }
        }
    }
}

void display_prime_numbers(int arr[])
{
    for (int i = 2; i < N; ++i)
    {
        if (arr[i]==1)
        {
            printf("%d", i);
            if (i<N-1)
            {
                printf(" ,");
            }
        }
    }
}


int main()
{
    int arr[N];

    for (int i = 0; i < N; ++i)
    {
        arr[i]=1;
    }

    eratosthenes(arr);

    printf("Prime numbers between 0 and %d are:", N);
    display_prime_numbers(arr);

    return 0;
}

//Dump

// for (int i = 0; i < N; ++i)
// {
//     printf("%d  ", arr[i]);
// }

// for (int i = 2; i < N; ++i)
// {
//     for (int j = i+1; j < N; ++j)
//     {
//         if (j%i==0)
//         {
//             arr[j]=0;
//         }
//     }
// }

// printf("\n");
//
// for (int i = 0; i < N; ++i)
// {
//     printf("%d  ", arr[i]);
// }