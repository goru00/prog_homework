#include<stdio.h> // стандартный заголовочный файл ввода-вывода
#include<math.h> // математическая библиотека
#define e 1e-13 // константа точности вычисления
double f1(double, double, double); // прототип функции f1
double f(double, double, double); // прототип функции f
double FindRoot(double,double,double); // прототип функции FindRoot
double f1(double x, double c, double d) // объявляем функцию f и передаем c, d и x
{ 
 return 3 * pow(x, 2)+c*2*x+d; // возвращаем значение производной 
} 
double f(double x, double c, double d) //объявляем функцию f и передаем c, d и x
{ 
 return pow(x,3)+c*pow(x, 2)+d; //возвращаем значение функции 
} 
double FindRoot(double x, double c, double d) //объявляем функцию f передаем c, d и x
{ 
 double x1; int i = 0; // объявляем переменные 
 do 
 { 
 do 
 { 
 x1 = x; // присваиваем переменной x1 значение x
 x = x - f(x,c,d) / f1(x,c,d); // реализуем метод касательных

 i++; // увеличиваем кол-во итераций
 } while(fabs(f(x,c,d)) >= e); //пока значение функция по модулю больше точности, выполняем
 } while (f(x,c,d)*f1(x1,c,d) < 0); //если при значение функции меньше 0, то выполняем
 printf("Kol-vo iteracii: %d\n", i); // выводим кол-во итераций
 return x; // возвращем значение x
} 
int main() // объявляем функцию main
{ 
 double c, d, x = 0; // объявляем переменные c, d и x
 printf("Введите значение c и d: "); // просим ввести значение c и d
 scanf("%lf %lf", &c, &d); // вводим значение c и d
 printf("f(x) = %lf\n", FindRoot(x, c, d)); // выводим корень уравнения
 return 0; 
}	
