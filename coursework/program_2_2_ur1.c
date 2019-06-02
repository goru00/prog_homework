#include <stdio.h>
#include <math.h>
#define eps 1e-13
typedef double (*func)(double x, double c, double d); // задаем тип func
double fx(double, double, double);      // прототип вычисляемой функции
double fx(double x, double d, double c) // вычисляемая функция
 {
  return pow(x, 5) + d*pow(x,2) - c;
 }

double decision(func fx, double x1, double x2, double c, double d)
 {
  double v; int i = 0;
  while (fabs(x1 - x2) > eps) // пока не достигнута точность eps(0.0000001)
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
  double c, d;
  double x1, x2; //х1, х2 - начало и конец отрезка, для которого применяем метод секущих
  printf("Введите интервал(x2 и x1): "); scanf("%lf %lf", &x1, &x2);// Вывод в консоль интервала
  printf("Введите значение c и d: "); scanf("%lf %lf", &c, &d);
  printf("x = %f\n", decision(fx, x1, x2, c, d)); // Вывод в консоль ответа
  return 0;
}
