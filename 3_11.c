#include<stdio.h>

main()
{
    float fctr, e = 1.0, n, i;
    printf("Введите число n: "); scanf("%f", &n);
    system("clear");
    fctr = n;
    i = n - 1.0;
    if (n == 1.0) e = e + 1.0;
    while (i != 0)
    {
        while (n != 0)
        {
            fctr = fctr * n;
            n = n - 1.0;
        }
        e = e + (1.0/fctr);
        i = i - 1.0;
        n = i;
        fctr = n + 1;
    }
    e = e + 1;
    printf("Выражение равно: %.3f\n", e);

    return 0;
}