#include<stdio.h>

main()
{

    int x10, x2, i = 0, x2_1, x2_0;
    printf("Введите число в десятичной системе счисления: "); scanf("%d", &x10);
    while (x10 != 0)
    {
        x2 = x10 % 2;
        if (x2 == 1)
         
        if (x2 == 0)
        
        x10 = x10 / 2;
    }
    printf("\n");
    return 0;
}