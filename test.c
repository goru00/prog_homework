#include<stdio.h>
#include<math.h>
double FindRoot(double, double);
double FindRoot(double eps, double x)
{
	int n = 0;
	double s = 0, a = x;
	while (fabs(a) > eps)
	{
		printf("n[%d]\t a = %lf\n", n, a);
		s += a/(4 * n + 1); n++;
		a *= pow(x, 4);
	} 
	printf("%d\n", n - 1);
	return s;
}
int main()
{
	double eps, x = 0.5;
	printf("Введите точность вычисления: "); scanf("%lf", &eps);
	printf("%lf\n", FindRoot(eps, x));
	return 0;
}