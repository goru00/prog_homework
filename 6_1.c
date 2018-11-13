#include<stdio.h>
#include<stdlib.h>
#define SIZE 9

int main()
{
    int A[SIZE];
    int i;
    srand(time(NULL));
    for (int i = 0; i <= SIZE; i++)
    {
        A[i] = (rand() % 100) + 1;
        printf("A[%d] = %d\n", i, A[i]);
    }
    int j, min, index_min;
    for (i = 0; i < SIZE; i++)
    {
        min = A[i];
        index_min = i;
        for (j = i; j <= SIZE; j++)
        
            if (min > A[j]) 
            {
                min = A[j];
                index_min = j;
            }
        A[index_min] = A[i];
        A[i] = min;
        
    }
    printf("\n\n");
    for (int i = 0; i <= SIZE; i++)
    {
        printf("a[%d] = %d\n", i, A[i]);
    }
    return 0;
}