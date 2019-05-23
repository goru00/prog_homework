#include<stdio.h>
#include<stdlib.h>
#include<math.h>
double f(double x, const double eps)
{
	int n = 0;
	double a = 1, s = 0;
	while (fabs(a) > eps)
	{
		s += a; n++; 
		a *= - x * (3 * n - 4)/(3 * n);
	}
	return s;
}
int main(int argc, char const *argv[])
{
	double x = 0.5;
	const double eps = 1e-16;
	printf("%lf\t%lf\n", cbrt(1+x), f(x, eps));
	return 0;
}