#include<stdio.h>
#include<math.h>
double FindRoot(double e)
{
    double s = 1.0, a = 1.0; int n = 1;
    while (fabs(a) >= e)
    {
        s+=a; n++;
        a *= 1.0/n;
    }
    return s;
}
int main()
{
    double eps;
    printf("Введите точность вычисления: "); scanf("%lf", &eps);
    printf("%lf\n", FindRoot(eps));
    return 0;
}