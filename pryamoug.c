#include<stdio.h>
#include<stdlib.h>
#include<math.h>
float FindRoot(float);
float FindRoot(float n)
{
	return n * log(n);
}
int main()
{
	int a = 1, b = 2;
	float S = 0, d, k, res;
	printf("Введите k: "); scanf("%f", &k);
	d = (b - a) / k;
	for (float x = a; x <= b; x+=d)
		S+=(FindRoot(x) * d);
	printf("%f\n", S);
	return 0;
}