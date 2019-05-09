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
		a *= - x * (2 * n - 3)/(2 * n);
	}
	return s;
}
int main(int argc, char const *argv[])
{
	double x = 0.5;
	const double eps = 1e-2;
	printf("%lf\t%lf\n", sqrt(1 + x), f(x, eps));
	return 0;
}