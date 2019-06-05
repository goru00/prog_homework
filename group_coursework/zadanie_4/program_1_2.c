#include<stdio.h>
#include<math.h>
double FindRoot(double eps)
{
    double s = 0, a = 1; int k = 1;
    for (int i = k; i >= 1; i--)
    {
        if (i % 2 == 0) {
            s = 1.0 / (2.0 + s);
        } else {
            s = 1.0 / (i - s);
        }
        if (fabs(M_E - (s + 1.0)) < eps) break;
        k++;
    }
    return s;
}
int main()
{
    double eps;
    printf("Введите точность: "); scanf("%lf", &eps);
    printf("%lf\t%lf\n", exp(1), FindRoot(eps));
    return 0;
}