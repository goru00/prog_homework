#include<stdio.h>
#include<stdlib.h>
int main()
{
    srand(time(NULL));
    int n, m;
    printf("Введите размерность(n и m): "); scanf("%d %d", &n, &m);
    int a[n][m];
    printf("\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            a[i][j] = (rand() % 100) + 1;
            printf("%6d", a[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    if (n == m)
        printf("Элементы массива симметричны.\n");
    return 0;
}