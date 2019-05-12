#include<stdio.h>
#include<stdlib.h>
#include<math.h>

double F(double);
double FindRoot(double (*)(double), double, double, double);

double FindRoot(double (*f)(double), double a, double b, double eps)
{
	double cde;
	while (abs(f(b) - f(a)) > eps)
	{
		cde = (f(b) * a - f(a) * b)/(f(b)-f(a));
		if ((f(a) * f(cde)) > 0) a = cde;
		else b = cde;
	}
	return cde;
}
double F(double x)
{
	return sin(4 * x) - 2;
}
int main()
{
	double a, b, eps, c, d, x;
	printf("Введите интервал(a и b): ");
	scanf("%lf %lf", &a, &b);
	if (F(a) * F(b) > 0)
		printf("Ошибка!\n");
	printf("Введите точность(eps. например: 0.0001): ");
	scanf("%lf", &eps);
	x = FindRoot(F, a, b, eps);
	printf("x = %lf\n", x);
	return 0;
}