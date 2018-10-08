#include<stdio.h>

int main()
{
    
    int x, p = 0, m, k, n1, n2, n4, n5;
    printf("Введите число: ");  scanf("%d", &x);
    system("clear");
    m = x;
    n1 = x / 10000;
    n2 = (x / 1000) % 10;
    n4 = (x % 100) / 10;
    n5 = x % 10;
    if ((n1 == n5) && (n2 == n4)) {
        printf("Это палиндром!\n");
    } else printf("Это не палиндром!\n");
    return 0;
}