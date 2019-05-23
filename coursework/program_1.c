#include<stdio.h>
#include<math.h>
double FindRoot(double);
double FindRoot(double eps)
{
	int n = 0; double s = 0, a = 1;
	while (fabs(a) > eps)
	{
		printf("n[%d]\t a = %lf\n", n, a);
		a *= 1.0/(2.0 * n + 1.0); s += a;
		n++;
	} 
	printf("%lf\t%d\n", s, n - 1); return s;
}
double FindDrob()
{
	double s = 0;
	for (int i = 1000; i > 0; i--) s = 1/(1 + i * s);
	printf("%lf\n", s);
	return s;
}
 int main()
{
	double eps;
	printf("Введите точность вычисления: "); scanf("%lf", &eps);
	printf("%lf\n",FindRoot(eps) + FindDrob());
	return 0;
} 
