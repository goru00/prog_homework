#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define PI 3.141592
#define eps 1e-9
double f(double x)
{
	int n = 1;
	double s = 0, a = cos(n * x);
	while (fabs(a) >= eps) 
	{
		s += pow(-1.0, n) * a; n++;
		a = (cos(n * x))/(n*n);
	}
	printf("Кол-во слагаемых: %d\n", n);
	return s;
}
int main()
{
	double x;
	printf("Введите значение x: "); scanf("%lf", &x);
	if ((x < PI/5) || (x > PI)) printf("Неверные данные!\n");
	else printf("%lf\t%lf\n", (1.0/4.0)*(x*x-(PI*PI)/3.0), f(x));
	return 0;
}