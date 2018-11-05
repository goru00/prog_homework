#include<stdio.h>
#include<math.h>
#define x 3
float sinpor(float n)
{
    int k = n;
    float fact, r = x;
    for (float n = 1; n <= k; n++)
    {
        //printf("%f\n", n);
        fact = 2 * n + 1;
        for (int i = fact - 1; i >= 1; i--)
        {
            fact = fact * i;
        }
        r = r + ((pow(-1, n) * pow(x, 2 * n + 1)) / fact); 
    }
    return r;
}

int main()
{
    float f;
    printf("Введите число n: "); scanf("%f", &f);
    printf("Синус числа %f равен: sin=%.3f\n", f, sinpor(f));

    return 0;
}