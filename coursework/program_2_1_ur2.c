#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define eps 0.00001
double f(double,double,double);
double FindRoot(double,double,double,double);
double f(double x,double c,double d)
{
	return pow(x,4)+c*pow(x,3)-d*x;
}
double FindRoot(double a,double b,double c, double d)
{
	double cde; int i = 0;
	while (b - a >= eps){
        cde = (a + b) / 2;
        if(f(b,c,d) * f(cde,c,d) < 0)
            a = cde;
        else
            b = cde;
        i++;
    }
    printf("Chislo iteracii: %d\n", i);
    return cde;
}
int main()
{
	double a,b,c,d,x;
	printf("Введите длину a и b: "); scanf("%lf%lf",&a,&b);
	printf("Введите c и d: "); scanf("%lf%lf",&c,&d);
	if(f(a,c,d)*f(b,c,d)>0)
		printf("Ф-я не имеет корней на данном отрезке\n");
	x = FindRoot(a,b,c,d);
	printf("x = %lf, f(x) = %lf\n",x,f(x,c,d));
	return 0;
}