/* Программа на вычисление ряда */
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
double fctr(double);
double fctr(double n)
{
	if (n == 1.0)
		return 1;
	else return n * fctr(n - 2.0);
}
int main()
{
	int count = 0;;
	double eps, fct = 2.0, n = 3.0, t = 1.0;
	printf("Введите точность вычисления: "); scanf("%lf", &eps);
	while (eps < fabs(t))
	{
		t = 1.0 / fctr(n);
		count++;
		fct +=t;
		n+=2;
	}
	printf("%lf\nЧленов ряда: %d\n", fct, count);
	return 0;
}