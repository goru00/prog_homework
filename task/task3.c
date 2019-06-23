#include<stdio.h>
#include<stdlib.h>
#include<math.h>
float f(float x, float y) {return (2*pow(x,3)+3*pow(y,3))/(3*pow(x,2)-2*pow(y,2));}
int main()
{
    printf("x\t\t\ty\t\t\tf(x,y)\n");
    for (float y = -2.0, x = 1.0; x <= 2.1; x+=0.1) {
        printf("%f\t\t%f\t\t%f\n", x, y, f(x,y));
        if (y < 2) y+=0.5;
    }
    return 0;
}