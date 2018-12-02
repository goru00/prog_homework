#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define VALUE_N 2
#define VALUE_M 4
int a[VALUE_N][VALUE_M];
int det_plus = 0, det_minus = 0, pr = 1;
int rektangle(int k)
{
    return a[0][0] * a[1][1] - a[0][1] * a[1][0];
    //Ну собсна ФУНКЦЫЯ ДЛЯ ВЫЧИСЛЕНИЯ КВАДРАТНОЙ МАТРИЦЫ 
}
int triangle(int k) // Метод Саррюса
{
    while (k <= 2)
    {
        for (int i = 0, j = k; j <= VALUE_N + k; i++, j++) // по диагонали "\"
        {
            pr *= a[i][j];
        }
        det_plus += pr;
        k++;
        pr = 1;
    }
    k = 0;
    while (k <= 2)
    {
        for (int i = 0, j = VALUE_M - k; j <= VALUE_N - k; i++, j--) // по диагонали "/"
        {
            pr = pr * a[i][j];
        }
        det_minus += pr;
        k++;
        pr = 1;
    }
    return det_plus - det_minus;
    //Все это дерьмо я мог просто засунуть в ретерн, но дядя Артамонов так не считает.
}

int main()
{
    int k;
    srand(time(NULL));
    for (int i = 0; i <= VALUE_N; i++)
    {
        k = 0;
        for (int j = 0; j <= VALUE_M; j++)
        {
            if (j >= 3) {
                a[i][j] = a[i][k];
                printf("%5d", a[i][j]);
                k++;    
            } else {
                a[i][j] = (rand() % 100) + 1;
                printf("%5d", a[i][j]);
            }
        }
        printf("\n");
    }
    k = 0;
    printf("Значение матрицы 3X3 равно: %d\n", triangle(k));
    printf("Значение матрицы 2X2 равно: %d\n", rektangle(k));
    return 0;
}