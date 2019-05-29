#include<stdio.h> 
#include<math.h> 
double f1(double, double, double); 
double f(double, double, double); 
double FindRoot(double,double,double,double); 
double f1(double x, double c, double d) 
{ 
 return c * cos(c * x); 
} 
double f(double x, double c, double d) 
{ 
 return sin(c * x) - d; 
} 
double FindRoot(double x, double c, double d, double e) 
{ 
 double x1; int i = 0; 
 do 
 { 
 do 
 { 
 x1 = x; 
 x = x - f(x,c,d) / f1(x,c,d); 
 printf("%lf\n", x); 
 i++; 
 } while(fabs(f(x,c,d)) >= e); 
 } while (f(x,c,d)*f1(x1,c,d) < 0); 
 printf("Kol-vo iteracii: %d\n", i); 
 return x; 
} 
int main() 
{ 
 double c, d, x = 0, e = 1e-13; 
 printf("Введите значение c и d: "); scanf("%lf %lf", &c, &d); 
 printf("x = %lf, f(x) = %lf\n", x, FindRoot(x, c, d, e)); 
 return 0; 
}