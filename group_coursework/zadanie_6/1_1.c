#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define PI 3.141592
double f(double x, double eps)
{
	int n = 1;
	double s = 0, a = cos(n * x);
	while (fabs(a) >= eps) 
	{
		s += pow(-1.0, n) * a; n++;
		a = cos(n * x);
		a /= (n * n);
	}
	return s;
}
int main()
{
	double eps, x = PI/5.0;
	printf("%lf\n", x);
	printf("Vvedite tochnost': "); scanf("%lf", &eps);
	printf("%lf\t%lf\n", (1.0/4.0)*(x*x-(PI*PI)/3.0), f(x, eps));
	return 0;
}