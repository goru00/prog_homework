#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main()
{
	int count = 1;
	double inf = 1.0, e, an = 1.0, sum = 1.0;
	printf("INPUT E: "); scanf("%lf", &e);
	while (e < fabs(inf))
	{
		inf = 1.0/an;
		an = 1.0 + 1.0/inf;
		sum += inf;
		count++;
	}
	printf("X: %lf\nDROB: %d\n", sum, count);
	return 0;
}