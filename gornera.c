#include<stdio.h>
#include<stdlib.h>
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
	int n = 6, x = 3;
	double a[] = {2, 3, 7, 8, 9, -1};
	double d=a[0]+a[1]*x+a[2]*pow(x, 2)+a[3]*pow(x, 3)+a[4]*pow(x, 4)+a[5]*pow(x, 5);
	printf("%lf\t%lf\n", d, gornera(n, a, x));
	return 0;
}