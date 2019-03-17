#include<stdio.h>
#include<stdlib.h>
#include<math.h>
void chainfraction(float);
void chainfraction(float eps) 
{
	int k = 3, count;
	double rma = 1.0, mn = 1.0, fract = 0;
	for (count = 0; fabs(rma) > eps; ++count, k+=2, mn = 1.0)
	{
		for (int i = 3; i <= k; i+=2)
			mn *= i;
		rma += 1.0/mn;
		fract +=rma;
	}
	printf("Членов ряда: %d\n", count);
}
int main()
{
	float eps;
	printf("Введите точность вычисления: "); scanf("%lf", &eps);
	chainfraction(eps);
	return 0;
}