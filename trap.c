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
	int a = 1, b = 2;
	float S = 0, k, d;
	printf("Введите k: "); scanf("%f", &k);
	d = (b - a) / k;
	S = (FindRoot(a) + FindRoot(b))/ 2;
	for (float x = a; x <= b - d; x+=d)
	{
		S+=(x * FindRoot(x));
		S*=d;
	}
	printf("%f\n", S);
	return 0;
}