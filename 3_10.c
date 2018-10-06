#include<stdio.h>

main()
{
    int x_10_start, x_2, i, x10_finish, a = 2;
    printf("Введите числов десятичной системе счисления: "); scanf("%d", &x_10);
    x_10_end = x_10;
    x_10_start = x_10;
    x_10_finish = 0;
    system("clear");
    printf("1");
    while ()
    {
        while (x_10_finish != 1)
        {
            x_10_start = x_10_start / 2;
            if (x_10_start == a) {
                x_2 = x_10_start % 2;
                if (x_10_start % 2 == 0)
                    a *=2;
                if (x_10_start % 2 == 1)
                    a = (a * 2) + 1;
                x_10_finish = 1;
            }
            if (x_10_start == b) {
                x_2 = x_10_start % 2;
                if 
                b *=2;
            }
        }
        if (x_2 == 0) printf("0"); 
        if (x_2 == 1) printf("1");
        x_10_finish = 0;
        x_10_start = x_10;
    }
    
}