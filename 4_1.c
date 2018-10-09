#include<stdio.h>

main()
{
    int i, krat = 1;
    for (i = 1; i <=15; i++)
    {
        if (i % 2 == 1)
        krat *=i;
    } 
    printf("Произведение от 1 до 15 равно: %d\n", krat);
    return 0;
}