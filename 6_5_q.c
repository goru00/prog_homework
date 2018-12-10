// Кароче хрен его знает. Правильно или нет уже сам не понимаю.
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main()
{
    int n, m, j, k;
    printf("Введите размерность массива: "); scanf("%d %d", &n, &m);
    int a[n][m];
    srand(time(NULL));
    for (int i = 0; i < n; i++)
    {
        if (j == m - i - 1)
            for (k = i + 1; k < n - i + 1; k++) // заполняет правую сторону
            {
                a[k][j] = rand() % 100 + 1;
                printf("a[%d][%d] = %d\n", k, j, a[k][j]);
            } 
        else if (k < n)
            for (k = i, j = 0; j < n; j++) // заполняет вверхнюю сторону
            {
                a[k][j] = rand() % 100 + 1;
                printf("a[%d][%d] = %d\n", k, j, a[k][j]); 
            }
        else if (k == n - i)
            for (j = m - 1; j >= 0; j--) // заполняем нижнюю сторону
            {
                a[k][j] = rand() % 100 + 1;
                printf("a[%d][%d] = %d\n", k, j, a[k][j]); 
            }
        else if (j < m)
            for (k = n - 1; k >= 0; k--) // заполняем левую сторону
            {
                a[k][j] = rand() % 100 + 1;
                printf("a[%d][%d] = %d\n", k, j, a[k][j]); 
            }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        { 
            printf("%5d", a[i][j]);
        }
        printf("\n");
    }
    return 0;
}