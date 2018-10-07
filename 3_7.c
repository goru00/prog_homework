#include<stdio.h>

main()
{
    int i = 1, z = 0, b = 0, a, f;
    printf("Введите число в 2-ой системе счисления: ");
    scanf("%d", &f);
    while (f != 0)
    {
        if (f <= 1023) {
            a = f % 2;
            f = (f-a) / 2;
            z = z + (a * i);
            i *=10;
        } else if (f >= 1024) {
            a = f % 2;
            f = (f-a) / 2;
            z = z + (a * i);
            i *=1; 
        }
    }
    printf("Число в двоичной системе счисления равно: %d\n", z);
    return 0;
}