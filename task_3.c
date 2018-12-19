#include<stdio.h>
#include<stdlib.h>
#include<math.h>

float fun(float x, float y);

float fun(float x, float y)
{
    return (2.0 * pow(x, 3.0) + 3.0 * pow(y, 3.0)) / (3.0 * pow(x, 2.0) - 2.0 * (y, 2.0));
}
int main()
{
    float a = 1.0, b = -2.0;
    printf("   x  \ty \tf\n");
    while (a <= 2.1)
    {
        printf("%6.3f %6.3f %3.1f\n", a, b, fun(a,b));
        a +=0.1;
        if (b < 2.0)
            b +=0.5;
    } 
    return 0;
}