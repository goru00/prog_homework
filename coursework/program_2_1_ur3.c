#include <stdio.h>
#include <math.h>
#define eps 0.00001
typedef double (*func)(double x, double c, double d); // задаем тип func
double fx(double, double, double); // прототип вычисляемой функции
double fx(double x, double c, double d) // вычисляемая функция
{
return sin(c * x) - d;
}
double decision(func fx, double x1, double x2, double c, double d)
{
double v, y; int i = 0;
do // пока не достигнута точность eps(0.0000001)
{
y = v;
v = (x1 * fx(x2, c, d) - x2 * fx(x1, c, d)) / (fx(x2, c, d) - fx(x1, c, d));
x1 = x2; x2 = v; i++;
} while (fabs(y - v) >= eps);
return x1;
}
int main()
{
double c, d;
double x1, x2; //х1, х2 - начало и конец отрезка, для которого применяем метод секущих
printf("Введите интервал(x2 и x1): "); scanf("%lf %lf", &x1, &x2);// Вывод в консоль интервала
printf("Введите значение c и d: "); scanf("%lf %lf", &c, &d);
printf("x = %lf\n", decision(fx, x1, x2, c, d)); // Вывод в консоль ответа
return 0;
}