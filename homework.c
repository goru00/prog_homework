#include<stdio.h>
#include<stdlib.h>
#include<math.h>
double f(double x, const double EPS)
{
	double s = 0;
	int n = 0;
	double a = 1; 
	while(fabs(a) > EPS)
	{
		s += a; n++;
		a *= -((x/n) * )/((2 * n - 2) * (2 * n));
	}
	return s;
}
int main()
{
	const double EPS = 1e-16;
	double x = 3;
	printf("%lf\t%lf\n", 1/sqrt(1 + x), f(x, EPS));
	return 0;
}