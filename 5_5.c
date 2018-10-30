#include<stdio.h>
#include<math.h>

int sinpor(int x)
{
    int n, i = x, k, sintown, r, fact;
    double sin1, sin2, sintack;
    sintack = x;
    while (x != 0)
    {
        r = x;
        fact = x;
        sintown =2 * i - 1;
        for (i = fact - 1; i >= 1; i--)
        {
            fact = fact * i;
        }
        for (i = x;i > 0; i--)
        {
            sin1 = pow((-1.0), i);
            sin2 = pow(x, 2.0 * i + 1.0);
            sintack = (sin1 * sin2) / fact;
        }
        r += sintack;
        x -=1;
    }
    return r;
}

int main()
{
    int f;
    printf("Введите число: "); scanf("%d", &f);
    printf("Синус числа %d равен: sin=%d", f, sinpor(f));

}