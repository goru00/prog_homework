/*6_2*/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
    int n;
    printf("Введите значение n: "); scanf("%d", &n);
    int a[n];
    srand(time(NULL));
    for (int i = 0; i < n; i++)
    {
        a[i] = (rand() % 100) + 1;
        printf("a[%d] = %d\n", i, a[i]);
    }
    int sr = (a[0] + a[1]) / 2;
    printf("\n");
    for (int i = 2; i < n; i++)
    {
        a[i] -= sr;
        sr = (a[i] + a[i - 1]) / 2; 
    }
    for (int i = 0; i < n; i++)
    {
        printf("a[%d] = %d\n", i, a[i]);
    }
    return 0;
}