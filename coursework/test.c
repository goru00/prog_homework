
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
 
int main() {
	int i;
	double E = 0.000001; // переменная для обозначения точности
	double a = 1/3.0, sum = 1/3.0;
  	//присваиваем переменным a(член ряда) и sum значение первого члена ряда
 	/*a *= (i+1)/(3*i) - формула для вычисления очередного члена ряда*/
 	for (i = 1; fabs(a *= (double)(i+1)/(3*i)) >= E; i++)
 	{
    	sum +=a;
 	}
 	printf("%lf", sum);;
 	return 0;
}