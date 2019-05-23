#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define eps 0.00001
double F(double, double, double);
double FindRoot(double (*)(double, double, double), double, double, double, double);
double F(double x, double c, double d)
{
    return pow(x, 5.0) + c * pow(x, 2.0) - d;
}
double FindRoot(double (*f)(double, double, double), double a, double b, double c, double d)
{
    double cde; int i = 0;
    while (fabs(f(b, c, d) - f(a, c, d)) >= eps)
    {
        cde= (a*f(b,c,d) - b*f(a,c,d)) / (f(b,c,d) - f(a,c,d));
        a=b; b=cde;
        i++;
    }
    printf("Iteracii: %d\n", i);
    return cde;
}
int main()
{
    double a, b, c, d, x;
    printf("Введите интервал(a и b): ");
    scanf("%lf %lf", &a, &b);
    printf("Введите значения параметров c и d: ");
    scanf("%lf %lf", &c, &d);
    if (F(a, c, d) * F(b, c, d) < 0)
        printf("Ошибка!\n");
    x = FindRoot(F, a, b, c, d);
    printf("x = %lf\n, f(x) = %lf\n", x, F(x,c,d));
    return 0;
}