#include<stdio.h>

main()
{
    int i, n, fctr;
    printf("Введите число: "); scanf("%d", &n);
    for (i = (n - 1); i >=1; i--)
        n *=i;
    system("clear");
    printf("Значение факториала равно: %d\n", n);
    return 0;
}