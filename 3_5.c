#include<stdio.h>

int main()
{
    
    int x, y, y1, x1, y2, x2;
    printf("Введите число: ");  scanf("%d", &x);
    system("clear");
    y = x / 10000;
    x = x % 10;

    y1 = x / 1000;
    y2 = y1 % 10;

    x1 = x / 10;
    x2 = x1 % 10;

    if ((y == x) && ((y2 == x2)) && (y1 == x2)) { 
        printf("Это палиндром!\n"); 
    } else printf("Это не палиндром!\n");
    
    return 0;
}