#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void input();
void output();
int main()
{
    srand(time(NULL));
    int **array;
    int n, m;
    printf("Введите размерность 2-ого массива: "); scanf("%d %d", &n, &m);
    array = (int **)malloc(n * sizeof(int));
    input(n, m, array);
    output(n, m, array);
    return 0;
}
void input(int size_n, int size_m, int **mass)
{
    for (int i = 0; i < size_n; i++)
    {
        mass[i] = (int *)malloc(size_m * sizeof(int));
        for (int j = 0; j < size_m; j++)
        {
            mass[i][j] = (rand() % 10);
        }
    }
}
void output(int size_n, int size_m, int **mass)
{
    for (int i = 0; i < size_n; i++)
    {
        for (int j = 0; j < size_m; j++)
        {
            printf("%3d", mass[i][j]);
        }
        printf("\n");
    }
    for (int i = 0; i < size_n; i++)
    {
        free(mass[i]);
    }
    free(mass);
}