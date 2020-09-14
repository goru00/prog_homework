#include<iostream>
#include<string>
#include<cmath>
#include<math.h>
using namespace std;
#define PI 3.141592653589793238462643383279
double f(double x, double eps)
{
double sum = 0, a;
int n = 1;
int k = x / (2.0 * PI);
x -= 2 * PI * k;
a = x;
while (abs(a) >= eps)
{
sum += a;
a *= (-1.0)*(x * x)/(2.0*n)/(2.0*n+1.0);
n++;
}
return sum;
}
int main()
{
double eps = 10e-15;
double x;
cin » x;
cout « sin(x) « "\t" « f(x, eps) « endl;
return 0;
}