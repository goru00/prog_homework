#include<stdio.h>

main()
{
    char x2 = "";
    int x10, i;
    printf("Введите число в десятичной системе счисления: "); scanf("%d", &x10);
    printf("\n");
    while (x10 != 0)
    {
        if (x10 % 2 == 1)
            x2 = x2 + "1";
        if (x10 % 2 == 0)
            x2 = x2 + "0";
        x10 = x10 / 2;
    }
    printf("%s\n",x2);
    return 0;
}