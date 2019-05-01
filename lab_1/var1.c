#include <stdio.h> 
#include <math.h> 
double F(double x, const double EPS) 
{ 
	double s=0, a=1,b; 
	int n=0; 
	x*=x; 
	while(fabs(a)>EPS) 
	{ 
		b=-2*a*x/((4*n+3)*(4*n+2)); 
		s+=a+b; 
		a=2*b*x/((4*n+5)*(4*n+4)); 
		n++; 
	}  
	return s*x; 
} 
int main() 
{ 
	const double EPS=1e-16; 
	double x=1; 
	printf("%lf\t%lf\n",sinh(x)*cos(x),F(x,EPS)); 
	return 0; 
}