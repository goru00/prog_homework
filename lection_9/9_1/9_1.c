#include<stdio.h>
#include<stdio.h>
void input();
int main()
{
    int n, m;
    printf("Введите кол-во строк и столбцов: "); scanf("%d %d", &n, &m);
    FILE *file = fopen("text", "a+");
    input(n, m, file);
    return 0;
}
void input(int size_n, int size_m, FILE *file)
{
    for (int i = 0; i < size_n; i++)
    {
        for (int j = 0; j < size_m; j++)
        {
            fprintf(file, "*");
        }
        fprintf(file, "\n");
    }
}