#include<stdio.h>
#include<stdlib.h>
#include<math.h>
double f(double x, const double eps)
{
	int n = 1;
	double a = x, s = 0;
	while (fabs(a) > eps)
	{
		s += a; n+=2; 
		a = - x/n;
	}
	return s;
}
int main(int argc, char const *argv[])
{
	double x = 2;
	const double eps = 1e-16;
	printf("%lf\t%lf\n", atan(x), f(x, eps));
	return 0;
}