// подключаем библиотеки
#include<stdio.h>
#include<stdlib.h>
#include<math.h> // библиотека для работы с математическими операциями
// объявлем прототипы функций
double F(double, double, double);
double FindRoot(double (*F)(double), double, double, double);
// функция для полинома
double F(double x, double c, double d)
{
	return sin(c * x) - d; 
	// возвращаем значение уравнения при заданных параметрах 
}
// функция нахождения корня
double FindRoot(double (*f)(double), double a, double b, double eps)
{
	double cde;
	while ((b - a)/2 > eps)
	{
		cde = (a + b) / 2;
		if ((f(a) * f(cde)) > 0) a = cde;
		else b = cde;
	}
	return cde;
}
int main()
{
	double a, b, eps, x, c, d;
	printf("Введите интервалы(a и b): "); scanf("%lf %lf", &a, &b);
	printf("Введите значение параметров c и d: "); scanf("%lf %lf", &c, &d);
	printf("Введите точность(eps(например: 0.0001)): "); scanf("%lf", &eps);
	x = FindRoot(F, a, b, eps);
	printf("Значение x = %lf\n", x);
	return 0;
}