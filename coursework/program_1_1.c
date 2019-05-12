#include<stdio.h>
#include<math.h>
double FindRoot(double);
double FindRoot(double eps)
{
	int n = 0;
	double s = 0, a = 1;
	while (fabs(a) > eps)
	{
		printf("n[%d]\t a = %lf\n", n, a);
		s += a;
		a *= 1.0/(2 * n + 1);
		n++;
	} 
	printf("%d\n", n - 1);
	return s;
}
int main()
{
	double eps;
	printf("Введите точность вычисления: "); scanf("%lf", &eps);
	printf("%lf\t%lf\n", pow((exp(1)*3.141592)/2, 0.5) ,FindRoot(eps));
	return 0;
}