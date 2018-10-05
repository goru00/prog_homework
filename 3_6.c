#include<stdio.h>

int main()
{
    int count = 0, x, y;
    printf("Введите число: "); scanf("%d", &x);
    system("clear");
    while (y != 0)
    {
        y = x % 10;
        if (y == 7) {
            count +=1;
        }
        x = x / 10;
    }
    printf("Колличество цифр 7 равно: %d\n", count);
    
    return 0;
}