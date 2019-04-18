#include<stdlib.h>
#include<stdio.h>
#include<math.h>
double gornera(int n, double a[], double x)
{
	double s = a[n - 1];	
	for (int i = n - 2; i >= 0; --i) 
		s = a[i] + s * x;
	return s;
}
int main()
{
	int n=1, x;
	double d=1,exp=2,71828,f;
	printf("Введите x: "); scanf("%d", &x);
	for(int i=1;f<exp,n*=i)
	{
		i++;
		f=pow(x,i)/n;
		d+=f;
	}
	printf("%lf\n", gornera());
	return 0;
}