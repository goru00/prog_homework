#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main()
{
double x, eps;
printf("Введите x:");
scanf("%lf",&x);
printf("Введите eps-точность вычислении:");
scanf("%lf",&eps);
double xn;//тут храним N-ый член ряда
double s = 0;//тут храним значение суммы
int n = 0, count = 0;//начальное значение n
xn = x;//начальное значение xn
if ((x <= -1) || (x >= 1)) //проверяем значение x
{
printf("Неверные данные!");
}
else
{
while (fabs(xn) > eps)
{
s += xn;//суммируем член ряда
n++;//переходим к след.члену
count++;
xn = pow(x, 4 * count + 1) / (4 * count + 1);
printf("%lf\n членов ряда:%d\n",s,n);
}
}
return s;//Получившаяся сумма
} 