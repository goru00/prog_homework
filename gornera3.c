#include<stdio.h>
#include<stdlib.h>
#include<math.h>
double f(double x, const double EPS)
{
	int n = 0;
	double a = 1;
	double s = 0; x *=x;
	while (fabs(a) > EPS)
	{
		s+=a; n++;
		a*= - x/((2 * n) * (2 * n - 1));
	}
	return s;
}
int main()
{
	double x = 2;
	const double EPS = 1e-16;
	printf("%lf\t%lf\n", cos(x), f(x, EPS));
	return 0;
}