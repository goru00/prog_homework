#include <stdio.h>
#include <math.h>
#define eps 1e-13
typedef double (*func)(double x, double c, double d); 
double FK(double, double, double);      
double FK(double x, double d, double c) 
 {
  return sin(d*x)-c;
 }
double dcs(func FK, double x1, double x2, double c, double d)
 {
  double v; int i = 0;
  while (fabs(x1 - x2) > eps) 
 {
    v = (x1 * FK(x2, c, d) - x2 * FK(x1, c, d)) / (FK(x2, c, d) - FK(x1, c, d));
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
  x = dcs(FK, x1, x2, c, d);
  printf("x = %f\n, f(x) = %lf\n", x, FK(x,c,d)); 
  return 0;
}