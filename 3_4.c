#include<stdio.h>

int main()
{
    int x, sum = 0;
    int y;
    printf("Введите число: "); scanf("%d", &x);
    y = x;
    system("clear");
    while (y != 0)
    {
        x = y % 10;
        sum = sum + x;
        y = y / 10;
    }
    printf("Сумма равна: %d\n", sum);

    return 0;
}