#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

int main()
{
    int n;
    printf("Введите размерность матрицы: "); scanf("%d", &n);
    int a[n][n];
    srand(time(NULL));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            a[i][j] = (rand() % 100) + 1;
            printf("%5d", a[i][j]);
        }
        printf("\n");
    }
    for (int k = 0, sum = 0; k != n - 1; k++)
    {
        printf("Сумма элементов ");
        for (int i = k + 1, j = 0; i < n; i++, j++)
        {
            sum += a[i][j];
            printf("a[%d][%d] ", i, j);
        }
        printf("равна = %d\n", sum);
        sum = 0;
        printf("Сумма элементов ");
        for (int i = k, j = k + 1; i < n - 1; i++, j++)
        {
            sum += a[i][j];
            printf("a[%d][%d] ", i, j);
        }
        printf("равна = %d\n", sum);
        sum = 0;
    }
    return 0;
}