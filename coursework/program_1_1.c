#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define eps 1e-6
double f(double,double,double);
double FindRoot(double,double,double,double,double);
double f(double x,double c,double d)
{
	return sin(c*x)-d;
}
double FindRoot(double a,double b,double x,double c, double d)
{
	double m; int i = 0;
	double lenght = b-a;
	if(fabs(f(a,c,d))<eps)
	return a;	
	else if(fabs(f(b,c,d))<eps)
	return b;
	while(lenght>=eps){
	m = (a+b)/2;// seredina otrezka
	if(fabs(f(m,c,d))<eps)
	  return m;	
	if(f(a,c,d) * f(m,c,d) < 0)
		b = m;
	else
		a = m;
	lenght/=2; i++;
    }
	printf("Кол-во итераций: %d\n", i);
    return m;
}
int main()
{
	double a,b,c,d,x;
	printf("Введите длину a и b: "); scanf("%lf%lf",&a,&b);
	printf("Введите c и d: "); scanf("%lf%lf",&c,&d);
	if(f(a,c,d)*f(b,c,d)>0)
		printf("Ф-я не имеет корней на данном отрезке\n");
	x = FindRoot(a,b,x,c,d);
	printf("x = %lf, f(x) = %lf\n",x,f(x,c,d));
	return 0;
}
