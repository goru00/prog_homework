#include<stdio.h>

main()
{
    float fctr, e = 1.0, fctr_finish, n, i;
    printf("Введите число n: "); scanf("%f", &n);
    system("clear");
    fctr = n;
    i = n - 1.0;
    fctr_finish = i;
    if (n == 1.0) e = e + 1.0;
    while (i != 0)
    {
        while (fctr_finish != 0)
        {
            fctr = fctr * fctr_finish;
            fctr_finish -= 1.0;
        }
        e = e + (1.0/fctr);
        i = i - 1.0;
        fctr_finish = i;
        n = n - 1.0;
        fctr = n - 1.0;
    }
    printf("Выражение равно: %f\n", e);

    return 0;
}