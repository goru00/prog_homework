#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<time.h>
#define SIZE 10

int main()
{
    int A[SIZE];
    srand(time(NULL));
    int i;
    for (i = 1; i<=SIZE; i++)
    {
        A[i - 1] = rand() % 1000;
        printf("%d; ", A[i - 1]);
    }
    printf("\n");
    int j, min, index_min;
    for (i = 0; i < SIZE; i++)
    {
        min = A[i];
        index_min = i;
        for (j = i; j < SIZE; j++)
        
            if (min > A[j]) 
            {
                min = A[j];
                index_min = j;
            }
        A[index_min] = A[i];
        A[i] = min;
        
    }
    for (i = 1; i <= SIZE; i++)
    {
        printf("%d; ", A[i - 1]);
    }
        printf("\n");
    
    return 0;
}