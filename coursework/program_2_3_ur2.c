#include<stdio.h>
#include<math.h>
#define e 0.00001
double f1(double, double, double);
double f(double, double, double);
double FindRoot(double,double,double,double);
double f1(double x, double c, double d)
{
	return 5.0 * pow(x, 4.0) + (c * 2.0) * pow(x, 1.0);
}
double f(double x, double c, double d)
{
	return pow(x, 5.0) + c * pow(x, 2.0) - d;
}
double FindRoot(double a, double b, double c, double d)
{
	double x;
	if (f(a,c,d)*f1(a,c,d) < 0)
    {
        x = a;
    } else {
        x = b;
    }
	double focus = fabs(f1(x,c,d));
	while(focus > e)
    {
            x = x - (f(x,c,d) / f1(x,c,d));
            printf("%lf\n", x);
            focus--; 
    }
    return x;
}
int main()
{
	double c, d, a, b, x;
	printf("Введите интервал: "); scanf("%lf %lf", &a, &b);
	printf("Введите значение c и d: "); scanf("%lf %lf", &c, &d);
	x = FindRoot(a,b,c,d);
	printf("x = %lf, f(x) = %lf\n", x, f(x,c,d));
	return 0;
}