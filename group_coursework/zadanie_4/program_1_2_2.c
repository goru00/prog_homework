#include<stdio.h> // стандартный заголовочный файл ввода-вывода
#include<math.h> // математическая библиотека
#define e 1e-13 // константа точности вычисления
double FK_proizv(double, double, double); // прототип функции f1
double FK(double, double, double); // прототип функции f
double dcs(double,double,double); // прототип функции FindRoot
double FK_proizv(double x, double c, double d) // объявляем функцию f и передаем c, d и x
{ 
 return c*cos(c*x)-d;//возвращаем значение производной 
} 
double FK(double x, double c, double d) //объявляем функцию f и передаем c, d и x
{ 
 return sin(c*x)-d; //возвращаем значение функции 
} 
double dcs(double x, double c, double d) //объявляем функцию f передаем c, d и x
{ 
 double x1; int i = 0; // объявляем переменные 
 do 
 { 
 do 
 { 
 x1 = x; // присваиваем переменной x1 значение x
 x = x - FK(x,c,d) / FK_proizv(x,c,d); // реализуем метод касательных

 i++; // увеличиваем кол-во итераций
 } while(fabs(FK(x,c,d))>=e); //пока значение функция по модулю больше точности, выполняем
 } while (FK(x,c,d)*FK_proizv(x1,c,d) < 0); //если при значение функции меньше 0, то выполняем
 printf("Kol-vo iteracii: %d\n", i); // выводим кол-во итераций
 return x; // возвращем значение x
} 
int main() // объявляем функцию main
{ 
 double c, d, x = 1; // объявляем переменные c, d и x, где x - длинна
 printf("Введите значение c и d: "); // просим ввести значение c и d
 scanf("%lf %lf", &c, &d); // вводим значение c и d
 printf("f(x) = %lf\n", dcs(x, c, d)); // выводим корень уравнения
 return 0; 
}	