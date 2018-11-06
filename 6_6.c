#include<stdio.h>
#include<stdlib.h>
#define VALUE 9

int main()
{
    int a[VALUE];
    srand(time(NULL));
    for (int i = 0; i <= VALUE; i++)
    {
        a[i] = (rand() % 100) + 1;
        printf("a[%d] = %d\n", i, a[i]);
    }
    printf("\na[0] = %d\n", a[0]);
    for (int i = 1; i < VALUE; i++)
    {
        a[i] = (a[i - 1] + a[i + 1]) / 2;
        printf("\na[%d] = %d\n", i, a[i]);
    }
    printf("\na[9] = %d\n", a[9]);
    return 0;
}