#include<stdio.h>
#include<stdlib.h>
#include<math.h>
double f(double x, const double EPS)
{
	int n = 0;
	double a = 1;
	double s = 0; x = pow(x, 2) * pow(x, 2);
	while (fabs(a) > EPS)
	{
		s+=a; n++;
		a*= - x/((2 * n) * (2 * n - 1));
	}
}
int main()
{
	const double EPS = 1e-16;
	double x = 2;
	printf("%lf\t %lf\n", ch(x) * sin(x), f(x, EPS));
	return 0;
}