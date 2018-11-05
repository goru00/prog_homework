#include<stdio.h>
int n;

void matrixinvers()
{
    srand(time(NULL));
    int A[n], max, min;
    for (int i = 0; i <= n; i++)
    {
        A[i] = (rand() % 100) - 1;
        printf("A[%d] = %d\n", i, A[i]);
    }
    for (int i = 0; i <= n; i++)
    {
        A[i] = min;
        A[n] = max;
        
        printf("A[%d] = %d\n", i, A[i]);
    }
}

int main()
{
    printf("Введите число n: "); scanf("%d", &n);
    matrixinvers();
}