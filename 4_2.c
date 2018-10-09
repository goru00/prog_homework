#include<stdio.h>

main()
{
    unsigned long long int i, n, fctr;
    printf("Введите число: "); scanf("%lld", &n);
    for (i = (n - 1); i >=1; i--)
        n *=i;
    system("clear");
    printf("Значение факториала равно: %lld\n", n);
    return 0;
}