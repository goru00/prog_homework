#include<stdio.h>
#include<stdlib.h>
#define VALUE 9

int main()
{
    int A[VALUE], min;
    srand(time(NULL));
    for (int i = 0; i <= VALUE; i++)
    {
        A[i] = (rand() % 100) + 1;
        printf("A[%d] = %d\n", i + 1, A[i]);
    }
    for (int i = 1; i <= VALUE; i++)
    {
        sleep(1);
        system("clear");
        for (int j = i; j <= VALUE; j++)
        {
            if (A[j] < A[j - 1]) { // второй элемент < первый элемент
                min = A[j];
                A[j] = A[j - 1];
                A[j - 1] = min;
            }
            printf("A[%d] = %d\n", j, A[j]);
        }
    }
    return 0;
}