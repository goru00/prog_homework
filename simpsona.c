#include<stdio.h>
#include<stdlib.h>
#include<math.h>
double FindRoot(float);
double FindRoot(float x)
{
	return x * log(x);
}
int main()
{
	float d, S = 0.0, k;
	int a = 1, b = 2;
	printf("Введите k: "); scanf("%f", &k);
	d = (b - a)/ (6 * k);
	for(float x = a; x <= b; x+=d)
		S += d * (FindRoot(a) + 4 * ((a+b) / 2) * FindRoot((a + b)/2) + b * FindRoot(b));
	printf("%lf\n", S);
	return 0;
}