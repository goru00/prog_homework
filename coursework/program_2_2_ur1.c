#include <stdio.h>
#include <math.h>
#define eps 1e-6
typedef double (*func)(double x, double c, double d); 
double fx(double, double, double);      
double fx(double x, double d, double c) 
 {
  return sin(d*x)-c;
 }
double decision(func fx, double x1, double x2, double c, double d)
 {
  double v; int i = 0;
  while (fabs(x1 - x2) > eps) 
 {
    v = (x1 * fx(x2, c, d) - x2 * fx(x1, c, d)) / (fx(x2, c, d) - fx(x1, c, d));
    x1 = x2; x2 = v;
	  i++;
  }
  printf("Итераций: %d\n", i);
  return x1;
 }

int main()
{
  double c, d, x;
  double x1, x2; 
  printf("Введите интервал(x1 и x2): "); scanf("%lf %lf", &x1, &x2);
  printf("Введите значение c и d: "); scanf("%lf %lf", &c, &d);
  x = decision(fx, x1, x2, c, d);
  printf("x = %f\n, f(x) = %lf\n", x, fx(x,c,d)); 
  return 0;
}
