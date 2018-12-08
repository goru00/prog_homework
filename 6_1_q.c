/*6_1*/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
int main()
{
    int n, k = 0;
    printf("Введите число n: "); scanf("%d", &n);
    int a[n*n];
    int b[n][n];
    srand(time(NULL));
    for (int i = 0; i < pow(n, 2); i++)
    {
        a[i] = (rand() % 100) + 1;
        printf("a[%d] = %d\n", i + 1, a[i]);
    }
    printf("\n\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            b[i][j] = a[k];
            k++;
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%5d", b[i][j]);
        }
        printf("\n");
    }
}