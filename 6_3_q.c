//6_3
#include<stdio.h>
#include<stdlib.h>

int main()
{
    int n;
    printf("Введите размерность массива: "); scanf("%d", &n);
    int a[n][n];
    for (int i = 0; i < n; i++)
    {
        if (i % 2 == 0) {
            for (int j = 0; j < n; j++)
            {
                if (j % 2 == 0)
                    a[i][j] = 0;
                else if (j % 2 == 1)
                    a[i][j] = 1;
            }
        }
        if (i % 2 == 1) {
            for (int j = 0; j < n; j++)
            {
                if (j % 2 == 0)
                    a[i][j] = 1;
                else if (j % 2 == 1)
                    a[i][j] = 0;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%5d", a[i][j]);
        }
        printf("\n");
    }
    return 0;
}