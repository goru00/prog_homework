#include<stdio.h>
#include<stdlib.h>
#include<math.h>
double f(double eps)
{
	int n;
	double s = 0, a = 1;
	for (n = 8; fabs(a) < ; n--) {
		a = 1.0 / (1.0 + (1.0/a));
	}
	printf("%d", n);
	return a;
}
int main()
{
	double eps;
	printf("Введите точность вычисления: "); scanf("%lf", &eps); 
	printf("\t%lf\n", f(eps));
	return 0;
}